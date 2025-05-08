#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <optional>
#include <functional>
#include <algorithm>
#include <memory>
#include <fstream>
#include <iomanip>

using namespace std;

enum class SortAlgorithms {
    BUBBLE,
    INSERTION,
    MERGE,
    QUICK,
    HEAP,
    STD
};

enum class SortBy {
    NAME,
    COUNTRY,
    POPULATION,
    LAT,
    LON
};

typedef struct {
    optional<SortAlgorithms> sorting_algorithms = nullopt;
    optional<SortBy> sort_by = nullopt;
    optional<int> num_to_display = nullopt;
    bool descending = false;
} SorterSettings;

enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

class csvReader {
public:
    static vector<vector<string> > readCSV(istream &in) {
        vector<vector<string> > table;
        string row;
        while (!in.eof()) {
            getline(in, row);
            if (in.bad() || in.fail()) {
                break;
            }
            auto fields = readCSVRow(row);
            table.push_back(fields);
        }
        return table;
    }

private:
    static vector<string> readCSVRow(const string &row) {
        CSVState state = CSVState::UnquotedField;
        vector<string> fields{""};
        size_t i = 0; // index of the current field
        for (char c: row) {
            switch (state) {
                case CSVState::UnquotedField:
                    switch (c) {
                        case ',': // end of field
                            fields.emplace_back("");
                            i++;
                            break;
                        case '"': state = CSVState::QuotedField;
                            break;
                        default: fields[i].push_back(c);
                            break;
                    }
                    break;
                case CSVState::QuotedField:
                    switch (c) {
                        case '"': state = CSVState::QuotedQuote;
                            break;
                        default: fields[i].push_back(c);
                            break;
                    }
                    break;
                case CSVState::QuotedQuote:
                    switch (c) {
                        case ',': // , after closing quote
                            fields.emplace_back("");
                            i++;
                            state = CSVState::UnquotedField;
                            break;
                        case '"': // "" -> "
                            fields[i].push_back('"');
                            state = CSVState::QuotedField;
                            break;
                        default: // end of quote
                            state = CSVState::UnquotedField;
                            break;
                    }
                    break;
            }
        }
        return fields;
    }
};

struct City {
    string name, country;
    double lat, lon;
    long population;

    static vector<City> get_cities_csv(const string &file_path) {
        vector<City> cities;
        fstream file(file_path);
        auto raw_data = csvReader::readCSV(file);


        for (const auto &row: raw_data) {
            try {
                cities.emplace_back(City{
                    .name = row[1],
                    .country = row[4],
                    .lat = stod(row[2]),
                    .lon = stod(row[3]),
                    .population = stol(row[9]),
                });
            } catch (...) {
            }
        }

        return cities;
    };
};

ostream &operator<<(ostream &os, const City &city) {
    os << "City => ";
    os << "Name: " << setfill(' ') << setw(20) << left << city.name << ", ";
    os << "Country: " << setfill(' ') << setw(20) << left << city.country << ", ";
    os << "Lat: " << setfill(' ') << setw(9) << right << fixed << showpoint << setprecision(4) << city.lat << ", ";
    os << "Lon: " << setfill(' ') << setw(9) << right << fixed << showpoint << setprecision(4) << city.lon << ", ";
    os << "Population: "  << fixed << showpoint << setprecision(4) << city.population << ", ";
    return os;
}

class CLIParser {
public:
    CLIParser(const int argc, char *argv[]) {
        this->argument_count = argc;
        // just so i can print them
        for (int i = 0; i < argc; i++) {
            this->arguments.emplace_back(argv[i]);
        }

        for (int i = 1; i < argc; i++) {
            if (strstr(argv[i], "-a")) {
                string str(argv[i + 1]);
                for (auto &ch: str) {
                    ch = static_cast<char>(tolower(ch));
                }
                set_sort_algorithm(str);
                continue;
            }

            if (strstr(argv[i], "-k")) {
                string str(argv[i + 1]);
                for (auto &ch: str) {
                    ch = static_cast<char>(tolower(ch));
                }
                set_sort_by(str);
            }

            if (strstr(argv[i], "-n")) {
                int temp = stoi(argv[i + 1]);
                this->num_to_display.emplace(temp);
                continue;
            }

            if (strstr(argv[i], "-r")) {
                this->descending = true;
                continue;
            }
        }
    }

    void print_arguments() const {
        for (int i = 0; i < argument_count; i++) {
            cout << arguments[i] << endl;
        }
    }

    void print_settings() const {
        cout << (this->sort_algorithm.has_value() ? static_cast<int>(this->sort_algorithm.value()) : -1) << endl;
        cout << (this->sort_by.has_value() ? static_cast<int>(this->sort_by.value()) : -1) << endl;
        cout << this->num_to_display.value_or(-1) << endl;
        cout << this->descending << endl;
    }

    [[nodiscard]] SorterSettings get_sorter_settings() const {
        return SorterSettings{
            .sorting_algorithms = this->sort_algorithm, .sort_by = this->sort_by,
            .num_to_display = this->num_to_display, .descending = this->descending
        };
    }

private:
    int argument_count;
    vector<string> arguments;

    optional<SortAlgorithms> sort_algorithm = nullopt;
    optional<SortBy> sort_by = nullopt;
    optional<int> num_to_display = nullopt;
    bool descending = false;

    void set_sort_by(const string &str) {
        if (str == "name") {
            this->sort_by.emplace(SortBy::NAME);
            return;
        }
        if (str == "country") {
            this->sort_by.emplace(SortBy::COUNTRY);
            return;
        }
        if (str == "population") {
            this->sort_by.emplace(SortBy::POPULATION);
            return;
        }
        if (str == "lat") {
            this->sort_by.emplace(SortBy::LAT);
            return;
        }
        if (str == "lon") {
            this->sort_by.emplace(SortBy::LON);
            return;
        }
        cerr << "Sort by key " << str << " is not supported" << endl;
    }

    void set_sort_algorithm(const string &str) {
        if (str == "bubble") {
            this->sort_algorithm.emplace(SortAlgorithms::BUBBLE);
            return;
        }
        if (str == "insertion") {
            this->sort_algorithm.emplace(SortAlgorithms::INSERTION);
            return;
        }
        if (str == "merge") {
            this->sort_algorithm.emplace(SortAlgorithms::MERGE);
            return;
        }
        if (str == "quick") {
            this->sort_algorithm.emplace(SortAlgorithms::QUICK);
            return;
        }
        if (str == "heap") {
            this->sort_algorithm.emplace(SortAlgorithms::HEAP);
            return;
        }
        if (str == "std") {
            this->sort_algorithm.emplace(SortAlgorithms::STD);
            return;
        }
        cerr << "Sorting algorithm " << str << " is not supported" << endl;
    }
};

template<typename T>
class Sorter {
public:
    virtual ~Sorter() = default;

    Sorter(const function<bool(const T &, const T &)> &cmp_fn,
           const SorterSettings &sorter_settings): cmp_fn(cmp_fn),
                                                   sorter_settings(sorter_settings) {
    };

    virtual void sort(vector<T> &data) = 0;

    [[nodiscard]] bool correct_sorting(const vector<T> &data) const {
        return is_sorted(data.begin(), data.end(), cmp_fn);
    }

    void print_sorted_data(vector<T> &data) const {
        int N;

        if (this->sorter_settings.num_to_display.has_value() &&
            this->sorter_settings.num_to_display.value() <= data.size()) {
            N = this->sorter_settings.num_to_display.value();
        } else {
            N = data.size();
        }
        for (int i = 0; i < N; i++) {
            cout << data[i] << endl;
        }
    }

protected:
    function<bool(const T &, const T &)> cmp_fn;
    SorterSettings sorter_settings;
};

template<typename T>
class BubbleSorter final : public Sorter<T> {
public:
    BubbleSorter(const function<bool(const T &, const T &)> &cmp_fn,
                 const SorterSettings &sorter_settings): Sorter<T>(cmp_fn, sorter_settings) {
    };

    // TODO: Bubble Sort Implementation
    void sort(vector<T> &data) override {
    }
};

template<typename T>
class InsertionSorter final : public Sorter<T> {
public:
    InsertionSorter(const function<bool(const T &, const T &)> &cmp_fn,
                    const SorterSettings &sorter_settings): Sorter<T>(cmp_fn, sorter_settings) {
    };

    // TODO: Insertion Sort Implementation
    void sort(vector<T> &data) override {
    }
};

template<typename T>
class MergeSorter final : public Sorter<T> {
public:
    MergeSorter(const function<bool(const T &, const T &)> &cmp_fn,
                const SorterSettings &sorter_settings): Sorter<T>(cmp_fn, sorter_settings) {
    };

    // TODO: Merge Sort Implementation
    void sort(vector<T> &data) override {
    }
};

template<typename T>
class QuickSorter final : public Sorter<T> {
public:
    QuickSorter(const function<bool(const T &, const T &)> &cmp_fn,
                const SorterSettings &sorter_settings): Sorter<T>(cmp_fn, sorter_settings) {
    };

    // TODO: Quick Sort Implementation
    void sort(vector<T> &data) override {
    }
};

template<typename T>
class HeapSorter final : public Sorter<T> {
public:
    HeapSorter(const function<bool(const T &, const T &)> &cmp_fn,
               const SorterSettings &sorter_settings): Sorter<T>(cmp_fn, sorter_settings) {
    };

    // TODO: Heap Sort Implementation
    void sort(vector<T> &data) override {
    }
};

template<typename T>
class StdSorter final : public Sorter<T> {
public:
    StdSorter(const function<bool(const T &, const T &)> &cmp_fn,
              const SorterSettings &sorter_settings): Sorter<T>(cmp_fn, sorter_settings) {
    };

    void sort(vector<T> &data) override {
        std::sort(data.begin(), data.end(), this->cmp_fn);
    }
};

template<typename T>
class SorterFactory {
public:
    explicit SorterFactory(const SorterSettings &sorter_settings): sorter_settings(sorter_settings) {
    };

    [[nodiscard]] std::unique_ptr<Sorter<City> > createSorter() {
        static_assert(sizeof(T) == 0, "NOT IMPLEMENTED");
        return nullptr;
    }

private:
    SorterSettings sorter_settings;
};

template<>
class SorterFactory<City> {
public:
    explicit SorterFactory(const SorterSettings &sorter_settings): sorter_settings(sorter_settings) {
    };

    [[nodiscard]] std::unique_ptr<Sorter<City> > createSorter() {
        function<bool(const City &, const City &)> cmp_fn;
        if (!this->sorter_settings.sorting_algorithms.has_value()) {
            cerr << "No Sorting Algorithm is provided to SorterFactory" << endl;
            return nullptr;
        }
        if (!this->sorter_settings.sort_by.has_value()) {
            cerr << "No Sorting Key is provided to SorterFactory" << endl;
            return nullptr;
        }
        switch (this->sorter_settings.sort_by.value()) {
            case SortBy::NAME: {
                cmp_fn = [&](const City &a, const City &b) {
                    return sorter_settings.descending ? (a.name > b.name) : (a.name < b.name);
                };
                break;
            }
            case SortBy::COUNTRY: {
                cmp_fn = [&](const City &a, const City &b) {
                    return sorter_settings.descending ? (a.country > b.country) : (a.country < b.country);
                };
                break;
            }
            case SortBy::LAT: {
                cmp_fn = [&](const City &a, const City &b) {
                    return sorter_settings.descending ? (a.lat > b.lat) : (a.lat < b.lat);
                };
                break;
            }
            case SortBy::LON: {
                cmp_fn = [&](const City &a, const City &b) {
                    return sorter_settings.descending ? (a.lon > b.lon) : (a.lon < b.lon);
                };
                break;
            }
            case SortBy::POPULATION: {
                cmp_fn = [&](const City &a, const City &b) {
                    return sorter_settings.descending ? (a.population > b.population) : (a.population < b.population);
                };
                break;
            }
        }

        switch (this->sorter_settings.sorting_algorithms.value()) {
            case SortAlgorithms::BUBBLE:
                return std::make_unique<BubbleSorter<City> >(cmp_fn, this->sorter_settings);
            case SortAlgorithms::INSERTION:
                return std::make_unique<InsertionSorter<City> >(cmp_fn, this->sorter_settings);
            case SortAlgorithms::MERGE:
                return std::make_unique<MergeSorter<City> >(cmp_fn, this->sorter_settings);
            case SortAlgorithms::QUICK:
                return std::make_unique<QuickSorter<City> >(cmp_fn, this->sorter_settings);
            case SortAlgorithms::HEAP:
                return std::make_unique<HeapSorter<City> >(cmp_fn, this->sorter_settings);
            case SortAlgorithms::STD:
                return std::make_unique<StdSorter<City> >(cmp_fn, this->sorter_settings);
        }
        return nullptr;
    }

private:
    SorterSettings sorter_settings;
};

int main(const int argc, char *argv[]) {
    auto data = City::get_cities_csv(R"(.\worldcities.csv)");

    const CLIParser parser(argc, argv);
    const SorterSettings sorter_settings = parser.get_sorter_settings();

    SorterFactory<City> sorter_factory(sorter_settings);

    const auto sorter = sorter_factory.createSorter();

    sorter->sort(data);
    sorter->print_sorted_data(data);

    cout << "Hello World" << endl;

    return 0;
}
