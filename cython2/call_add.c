// call_add.c
#include <Python.h>

int main() {
    Py_Initialize();

    PyObject *sys_path = PySys_GetObject("path");
    PyObject *path = PyUnicode_FromString(".");
    PyList_Append(sys_path, path);
    Py_DECREF(path);

    PyObject *pName = PyUnicode_FromString("add");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "add");

        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject *pArgs = PyTuple_Pack(2, PyLong_FromLong(10), PyLong_FromLong(20));
            PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != NULL) {
                long result = PyLong_AsLong(pValue);
                printf("Result: %ld\n", result);
                Py_DECREF(pValue);
            }
            Py_DECREF(pFunc);
        }
        Py_DECREF(pModule);
    }

    Py_Finalize();
    return 0;
}

