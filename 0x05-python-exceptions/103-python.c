#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Print basic info about Python lists
 * @p: PyObject pointer to a Python list
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	if (!PyList_Check(p))
	{
		fprintf(stderr, "Invalid List Object\n");
		return;
	}

	size = PyList_Size(p);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; ++i)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}

/**
 * print_python_bytes - Print basic info about Python bytes
 * @p: PyObject pointer to a Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *str;

	if (!PyBytes_Check(p))
	{
		fprintf(stderr, "Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	printf("[.] bytes object info\n");
	printf("size: %ld\n", size);

	str = PyBytes_AsString(p);

	printf("trying string: %s\n", str);

	if (size > 10)
		size = 10;

	printf("first %ld bytes: ", size);
	for (i = 0; i < size; ++i)
		printf("%02hhx ", str[i]);
	printf("\n");
}

/**
 * print_python_float - Print basic info about Python float
 * @p: PyObject pointer to a Python float object
 */
void print_python_float(PyObject *p)
{
	double value;

	if (!PyFloat_Check(p))
	{
		fprintf(stderr, "Invalid Float Object\n");
		return;
	}

	value = ((PyFloatObject *)p)->ob_fval;
	printf("[.] float object info\n");
	printf("value: %lf\n", value);
}
