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
        std::vector<std::string> inputParams{};
        std::vector<std::string> inputValues{};
        std::stringstream ss{};

        auto handler = [&] {
            std::string input = ss.str();
            if (input[0] == '-') {
                if (inputParams.size() != inputValues.size()) {
                    inputValues.emplace_back("");
                }
                inputParams.emplace_back(input);
            } else {
                inputValues.emplace_back(input);
            }
            ss = std::stringstream{};
        };

        for (char c : commands) {
            if (c != ' ') {
                ss << c;
            } else {
                handler();
            }
        }

        if (!ss.str().empty()) {
            handler();
        }

        if (inputParams.size() != inputValues.size()) {
            inputValues.emplace_back("");
        }

        auto handler2 = []<typename T>(auto& o, auto& v, auto f) {
            T& param = *std::any_cast<T*>(o.param_);
            if (!v.empty()) {
                param = f(v);
            } else {
                if (o.value_.has_value()) {
                    param = std::any_cast<T>(o.value_);
                }
            }
        };

        auto handler3 = []<typename T>(auto& o) {
            T& param = *std::any_cast<T*>(o.param_);
            param = std::any_cast<T>(o.value_);
        };

        std::size_t N = inputParams.size();
        for (Option& option : optionList_) {
            bool found = false;
            for (std::size_t i=0; i<N; ++i) {
                const std::string& inputParam = inputParams[i];
                const std::string& inputValue = inputValues[i];
                if (option.name_ == inputParam) {
                    if (option.param_.type() == typeid(std::string*)) {
                        handler2.operator()<std::string>(option, inputValue, [](auto s){return s;});
                    } else if (option.param_.type() == typeid(int*)) {
                        handler2.operator()<int>(option, inputValue, [](auto& s){return atoi(s.c_str());});
                    } else if (option.param_.type() == typeid(double*)) {
                        handler2.operator()<double>(option, inputValue, [](auto& s){return atof(s.c_str());});
                    } else if (option.param_.type() == typeid(bool*)) {
                        handler2.operator()<bool>(option, inputValue, [](auto& s){return s == "true";});
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (option.param_.type() == typeid(std::string*)) {
                    handler3.operator()<std::string>(option);
                } else if (option.param_.type() == typeid(int*)) {
                    handler3.operator()<int>(option);
                } else if (option.param_.type() == typeid(double*)) {
                    handler3.operator()<double>(option);
                } else if (option.param_.type() == typeid(bool*)) {
                    handler3.operator()<bool>(option);
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
    commandLineParser.parse("--ip 127.0.0.1 --port 12345 --verbose true");
    std::cout << timeout << std::endl;
    std::cout << ip << std::endl;
    std::cout << port << std::endl;
    std::cout << std::boolalpha << verbose << std::endl;

    return 0;
}
