#include <iostream>
#include <cstring>
#include <vector>
#include <optional>

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
                if (str == "bubble") {
                    this->sort_algorithm.emplace(SortAlgorithms::BUBBLE);
                    continue;
                }
                if (str == "insertion") {
                    this->sort_algorithm.emplace(SortAlgorithms::INSERTION);
                    continue;
                }
                if (str == "merge") {
                    this->sort_algorithm.emplace(SortAlgorithms::MERGE);
                    continue;
                }
                if (str == "quick") {
                    this->sort_algorithm.emplace(SortAlgorithms::QUICK);
                    continue;
                }
                if (str == "heap") {
                    this->sort_algorithm.emplace(SortAlgorithms::HEAP);
                    continue;
                }
                if (str == "std") {
                    this->sort_algorithm.emplace(SortAlgorithms::STD);
                    continue;
                }

                cout << "SORTING ALGORITHM " << str << " NOT SUPPORTED" << endl;
                continue;
            }

            if (strstr(argv[i], "-k")) {
                string str(argv[i + 1]);
                for (auto &ch: str) {
                    ch = static_cast<char>(tolower(ch));
                }
                if (str == "name") {
                    this->sort_by.emplace(SortBy::NAME);
                    continue;
                }
                if (str == "country") {
                    this->sort_by.emplace(SortBy::COUNTRY);
                    continue;
                }
                if (str == "population") {
                    this->sort_by.emplace(SortBy::POPULATION);
                    continue;
                }
                if (str == "lat") {
                    this->sort_by.emplace(SortBy::LAT);
                    continue;
                }
                if (str == "lon") {
                    this->sort_by.emplace(SortBy::LON);
                    continue;
                }
                cout << "SORT BY KEY " << str << " NOT AVAILABLE" << endl;
                continue;
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
        cout << static_cast<int>(this->sort_algorithm.value()) << endl;
        cout << static_cast<int>(this->sort_by.value()) << endl;
        cout << this->num_to_display.value() << endl;
        cout << this->descending << endl;
    }

    [[nodiscard]] optional<SortAlgorithms> get_sort_algorithm() const {
        return sort_algorithm;
    }

    [[nodiscard]] optional<SortBy> get_sort_by() const {
        return sort_by;
    }

    [[nodiscard]] optional<int> get_num_to_display() const {
        return num_to_display;
    }

    [[nodiscard]] bool is_descending() const {
        return descending;
    }

private:
    int argument_count;
    vector<string> arguments;

    optional<SortAlgorithms> sort_algorithm = nullopt;
    optional<SortBy> sort_by = nullopt;
    optional<int> num_to_display = nullopt;
    bool descending = false;
};


int main(const int argc, char *argv[]) {
    CLIParser parser(argc, argv);
    parser.print_settings();
}
