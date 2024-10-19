#include <stdio.h>
#include <Python.h>
#include "libmypy.h"

PyObject * hello(PyObject * self) {
	return PyUnicode_FromFormat("Hello C extension!");
}

PyObject * heyman(PyObject *self, PyObject *args) {
	int num;
	char *name;

	if(!PyArg_ParseTuple(args, "is", &num, &name))
		return NULL;

	return PyUnicode_FromFormat("Hay %s!  You gave me %d.", name, num);
}

PyObject * add(PyObject *self, PyObject *args) {
	int num1, num2;
	char eq[20];

	if(!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return NULL;

	sprintf(eq, "%d + %d", num1, num2);

	return Py_BuildValue("is", num1 + num2, eq);
}

PyObject * arg_passing_test(PyObject *self, PyObject *args) {
	int num1, num2, num3, num4, num5, num6;

	if(!PyArg_ParseTuple(args, "iiiiii", &num1, &num2, &num3, 
		&num4, &num5, &num6))
		return NULL;

	// these two lets us release the global interpreter lock in C
	// however, this means we aren't allowed tokk
	Py_BEGIN_ALLOW_THREADS;
	assert(!PyGILState_Check());
	printf("Hello world, maybe?\n");

	Py_END_ALLOW_THREADS;
	
	return Py_BuildValue("iiiiii", num6, num5, num4, num3, num2, num1);
}
