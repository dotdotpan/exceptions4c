
# include <string.h>
# include "testing.h"


static void set_zero_g04(int * * pointer){

	int * null_pointer = NULL;

	memcpy(pointer, &null_pointer, sizeof(pointer) );
}


DEFINE_TEST(
	g04,
	"Bad pointer exception",
	"This test attempts to dereference a null pointer; the library signal handling is enabled; there is no <code>catch</code> block. The behavior of the program will no longer be undefined: it will terminate because of the uncaught exception <code>BadPointerException</code>.",
	"This functionality relies on the <a href=\"#requirement_z07\"><strong>platform's ability to handle signal <code>SIGSEGV</code></strong></a>.",
	( E4C_VERSION_THREADSAFE ? EXIT_WHATEVER : EXIT_FAILURE ),
	"before_NULL_POINTER",
	"BadPointerException"
){

	int		integer			= 123;
	int *	pointer			= &integer;

	ECHO(("before_CONTEXT_BEGIN\n"));

	e4c_context_begin(e4c_true, e4c_print_exception);

	/* some smartypants compilers might need to be fooled */
	/* pointer = NULL; */

	ECHO(("before_SET_NULL\n"));

	set_zero_g04(&pointer);

	ECHO(("before_NULL_POINTER\n"));

	integer = *pointer;

	ECHO(("after_NULL_POINTER_%d\n", integer));

	ECHO(("before_CONTEXT_END\n"));

	e4c_context_end();

	ECHO(("after_CONTEXT_END\n"));

	return(EXIT_SUCCESS);
}
