#include <nanobind/nanobind.h>
namespace nb = nanobind;

void say_hello(const std::string &name) {
    printf("Hello, %s!\n", name.c_str());
}

NB_MODULE(hello, m) {
    m.def("say_hello", &say_hello, "A function that prints 'Hello'");
}
