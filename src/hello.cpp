#include <Python.h>

static PyObject* say_hello(PyObject* self, PyObject* args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return NULL;
    }
    printf("Hello, %s!\n", name);
    Py_RETURN_NONE;
}

static PyMethodDef HelloMethods[] = {
    {"say_hello", say_hello, METH_VARARGS, "Print 'Hello'"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",
    NULL,
    -1,
    HelloMethods
};

PyMODINIT_FUNC PyInit_hello(void) {
    return PyModule_Create(&hellomodule);
}
