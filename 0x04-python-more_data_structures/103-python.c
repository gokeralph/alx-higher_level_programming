#include <Python.h>
#include <stdio.h>
/**
 * print_python_list - prints python list
 * @p: valid PyBytesObject
 * Return: python bytes
 */

void print_python_list(PyObject *p) {
    Py_ssize_t i, size;
    PyObject *item;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0, size = PyList_Size(p); i < size; i++) {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    Py_ssize_t i, size;
    char *str;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));

    printf("  first 10 bytes: ");
    str = PyBytes_AsString(p);
    for (i = 0; i < size && i < 10; i++) {
        printf("%02hhx", str[i]);
        if (i < 9 && i < size - 1)
            printf(" ");
    }
    printf("\n");
}
