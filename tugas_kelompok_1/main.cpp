#include <iostream>
#include <cstring>
#include <vector>
#include <optional>
#include <functional>


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
} SortingSettings;


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

    [[nodiscard]] SortingSettings get_sorting_settings() const {
        return SortingSettings {
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
        cout << "SORT BY KEY " << str << " NOT AVAILABLE" << endl;
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
        cout << "SORTING ALGORITHM " << str << " NOT SUPPORTED" << endl;
    }
};

template<typename T>
class Sorter {
public:
    virtual ~Sorter() = default;

    Sorter(vector<T> data, std::function<int(T, T)> cmp_fn): data(data), cmp_fn(cmp_fn) {
    };

    virtual void sort() = 0;

private:
    vector<T> data;
    std::function<int(T, T)> cmp_fn;
};

template<typename T>
class BubbleSorter : public Sorter<T> {
public:
    void sort() override {
    }
};

template<typename T>
class InsertionSorter : public Sorter<T> {
public:
    void sort() override {
    }
};

template<typename T>
class MergeSorter : public Sorter<T> {
public:
    void sort() override {
    }
};

template<typename T>
class QuickSorter : public Sorter<T> {
public:
    void sort() override {
    }
};

template<typename T>
class HeapSorter : public Sorter<T> {
public:
    void sort() override {
    }
};

template<typename T>
class StdSorter : public Sorter<T> {
public:
    void sort() override {
    }
};

template<typename T>
class SorterFactory {
public:
    SorterFactory(SortingSettings sorter_settings) {};

private:
    SortingSettings sorter_settings;

};

int main(const int argc, char *argv[]) {
    CLIParser parser(argc, argv);
    parser.print_settings();
}
