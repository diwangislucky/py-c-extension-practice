#include "libmypy.h"

char hellofunc_docs[] = "Hello world description.";
char heymanfunc_docs[] = "Echo your name and passed number.";
char addfunc_docs[] = "Add two numbers function.";
char arg_passing_docs[] = "Testing if I could pass 6 integers and get away with it";

PyMethodDef helloworld_funcs[] = {
	{	"hello",
		(PyCFunction)hello,
		METH_NOARGS,
		hellofunc_docs},
	{	"heyman",
		(PyCFunction)heyman,
		METH_VARARGS,
		heymanfunc_docs},
	{	"add",
		(PyCFunction)add,
		METH_VARARGS,
		addfunc_docs},
	{	"arg_passing_test",
		(PyCFunction)arg_passing_test,
		METH_VARARGS,
		arg_passing_docs},
	{	NULL}
};

char helloworldmod_docs[] = "This is hello world module.";

PyModuleDef helloworld_mod = {
	PyModuleDef_HEAD_INIT,
	"helloworld",
	helloworldmod_docs,
	-1,
	helloworld_funcs,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_helloworld(void) {
	return PyModule_Create(&helloworld_mod);
}
