#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
 * print_python_list - Prints information about Python lists
 * @p: Pointer to the PyObject (Python list)
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *element;

	size = PyList_Size(p);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		element = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(element)->tp_name);
		if (PyBytes_Check(element))
			print_python_bytes(element);
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

	printf("[.] bytes object info\n");
	size = PyBytes_Size(p);
	printf("  size: %ld\n", size);

	string = PyBytes_AsString(p);
	printf("  trying string: %s\n", string);

	printf("  first 10 bytes: ");
	for (i = 0; i < size && i < 10; i++)
		printf("%02hhx ", string[i]);
	printf("\n");
}
