#include <iostream>

void process_value(std::string& v) {
    std::cout << "process_value(T& v): " << v << std::endl;
}

void process_value(const std::string& v) {
    std::cout << "process_value(const T& v): " << v << std::endl;
}

void process_value(std::string&& v) {
    std::cout << "process_value(T&& v): " << v << std::endl;
}

void process_value(const std::string&& v) {
    std::cout << "process_value(const T&& v): " << v << std::endl;
}

template<typename T>
void forward_value(T&& v) {
    process_value(std::forward<T>(v));
}

const std::string const_rvalue() {
    return "hello const";
}

std::string nonconst_rvalue() {
    return "hello nonconst";
}

int main() {
    std::string a = "hello lvalue";
    const std::string& b = a;

    forward_value(a);
    forward_value(b);
    forward_value(nonconst_rvalue());
    forward_value(const_rvalue());
}
