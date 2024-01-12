#include <stdlib.h>
#include <Python.h>
#include "/usr/include/python3.4/bytesobject.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_python_list - Prints information about Python lists
 * @p: Pointer to the PyObject (Python list)
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *element;

	if (!PyList_Check(p))
	{
		fprintf(stderr, "[ERROR] Invalid Python List\n");
		return;
	}

	size = PyList_Size(p);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		element = PyList_GetItem(p, i);
		if (element == NULL)
		{
			fprintf(stderr, "[ERROR] Element retrieval failed\n");
			return;
		}

		printf("Element %ld: %s\n", i, Py_TYPE(element)->tp_name);
	}
}

/**
 * print_python_bytes - Prints information about Python bytes
 * @p: Pointer to the PyObject (Python bytes)
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *string;

	if (!PyBytes_Check(p))
	{
		fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("[.] bytes object info\n");
	size = PyBytes_Size(p);
	printf("  size: %ld\n", size);

	string = PyBytes_AsString(p);
	if (string == NULL)
	{
		fprintf(stderr, "[ERROR] Unable to retrieve string data\n");
		return;
	}

	printf("  trying string: %s\n", string);

	printf("  first 10 bytes: ");
	for (i = 0; i < size && i < 10; i++)
		printf("%02hhx ", string[i]);
	printf("\n");
}
