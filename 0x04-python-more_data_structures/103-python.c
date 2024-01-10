#include <stdio.h>
#include "/usr/include/python3.4/Python.h"

/**
 * print_python_bytes - Print information about Python bytes object
 * @p: PyObject pointer
 */
void print_python_bytes(PyObject *p)
{
	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("  size: %ld\n", PyBytes_GET_SIZE(p));
	printf("  trying string: ");
	fflush(stdout);

	char *str = PyBytes_AS_STRING(p);

	for (Py_ssize_t i = 0; i < 10 && i < PyBytes_GET_SIZE(p); ++i)
		printf("%02x ", str[i]);
	printf("\n");
}

/**
 * print_python_list - Print information about Python list
 * @p: PyObject pointer
 */
void print_python_list(PyObject *p)
{
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (Py_ssize_t i = 0; i < PyList_Size(p); ++i)
	{
		printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
		if (PyBytes_Check(PyList_GetItem(p, i)))
		{
			print_python_bytes(PyList_GetItem(p, i));
		}
	}
}
