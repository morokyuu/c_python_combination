// call_add.c
#include <Python.h>
#include <stdio.h>

int main() {
    Py_Initialize();

    PyObject *sys_path = PySys_GetObject("path");
    PyObject *path = PyUnicode_FromString(".");
    PyList_Append(sys_path, path);
    Py_DECREF(path);

    PyObject *pName = PyUnicode_FromString("hello");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "say_hello_to");

        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject *pArg = PyUnicode_FromString("Mameichi");

            PyObject *pArgs = PyTuple_Pack(1,pArg);
            Py_DECREF(pArg);

            PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != NULL) {
                const char *result = PyUnicode_AsUTF8(pValue);
                printf("Python returned: %s\n", result);
                Py_DECREF(pValue);
            }
            else{
                PyErr_Print();
                fprintf(stderr, "Function call failed\n");
            }
            Py_DECREF(pFunc);
        } else {
            PyErr_Print();
            fprintf(stderr, "Cannot find function\n");
        }
        Py_DECREF(pModule);
    }

    Py_Finalize();
    return 0;
}

