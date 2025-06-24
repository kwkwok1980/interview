/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <type_traits>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <any>
#include <optional>

struct Option {
    std::string name_;
    std::any param_;
    std::any value_;
};

struct CommandLineParser {

    template<typename T>
    void add_option(const std::string& name, T& param, const T& value) {
        Option option{};
        option.name_ = name;
        option.param_ = &param;
        option.value_ = value;
        optionList_.push_back(option);
    }

    template<typename T>
    void add_option(const std::string& name, T& param) {
        Option option{};
        option.name_ = name;
        option.param_ = &param;
        optionList_.push_back(option);
    }

    void parse(const std::string& commands) {
        std::vector<std::string> inputs{};
        std::stringstream ss{};
        for (char c : commands) {
            if (c != ' ') {
                ss << c;
            } else {
                inputs.emplace_back(ss.str());
                ss = std::stringstream{};
            }
        }

        if (!ss.str().empty()) {
            inputs.emplace_back(ss.str());
        }

        auto handler1 = []<typename T>(auto& o, auto& v, auto f) {
            T& param = *std::any_cast<T*>(o.param_);
            if (!v.empty()) {
                param = f(v);
            } else {
                if (o.value_.has_value()) {
                    param = std::any_cast<T>(o.value_);
                }
            }
        };

        auto handler2 = []<typename T>(auto& o) {
            T& param = *std::any_cast<T*>(o.param_);
            param = std::any_cast<T>(o.value_);
        };

        std::size_t N = inputs.size();
        for (Option& option : optionList_) {
            std::optional<std::string> inputParam{};
            std::optional<std::string> inputValue{};
            for (int i=0; i<N; ++i) {
                if (inputs[i] == option.name_) {
                    inputParam = inputs[i];
                    if (i < N-1) {
                        if (inputs[i + 1][0] != '-') {
                            inputValue = inputs[i + 1];
                        }
                    }
                    break;
                }
            }
            if (option.param_.type() == typeid(std::string*)) {
                if (inputParam && inputValue) {
                    handler1.operator()<std::string>(option, *inputValue, [](auto s){return s;});
                } else {
                    handler2.operator()<std::string>(option);
                }
            } else if (option.param_.type() == typeid(int*)) {
                if (inputParam && inputValue) {
                    handler1.operator()<int>(option, *inputValue, [](auto& s){return atoi(s.c_str());});
                } else {
                    handler2.operator()<int>(option);
                }
            } else if (option.param_.type() == typeid(double*)) {
                if (inputParam && inputValue) {
                    handler1.operator()<double>(option, *inputValue, [](auto& s){return atof(s.c_str());});
                } else {
                    handler2.operator()<double>(option);
                }
            } else if (option.param_.type() == typeid(bool*)) {
                if (inputParam) {
                    inputValue = inputValue ? *inputValue : std::string{"true"};
                    handler1.operator()<bool>(option, *inputValue, [](auto& s){return s == "true";});
                } else {
                    handler2.operator()<bool>(option);
                }
            }
        }
    }

    std::vector<Option> optionList_{};
};


int main() {
    int timeout{};
    std::string ip{};
    int port{};
    bool verbose{};
    CommandLineParser commandLineParser{};
    commandLineParser.add_option("--ip", ip);
    commandLineParser.add_option("--port", port);
    commandLineParser.add_option("--timeout", timeout, 5);
    commandLineParser.add_option("--verbose", verbose, false);
    commandLineParser.parse("--ip 127.0.0.1 --port 12345 --verbose");
    std::cout << timeout << std::endl;
    std::cout << ip << std::endl;
    std::cout << port << std::endl;
    std::cout << std::boolalpha << verbose << std::endl;

    return 0;
}
