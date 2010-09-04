
# include "testing.h"

static void * e4c_acquire_buffer(size_t bytes){

	void * buffer;

	buffer = malloc(bytes);

	return(buffer);
}

static void e4c_dispose_buffer(void * buffer, e4c_bool failed){

	if(failed){

		free(buffer);

		return;
	}

	free(buffer);
}


DEFINE_TEST(
	b04,
	"using{...} after having ended",
	"This test uses the library in an inconsistent way, by attempting to <strong>start a <code>using</code> block</strong>, after having called <code>e4c_context_end()</code>. The library must signal the misuse by throwing the exception <code>ContextHasNotBegunYet</code>.",
	EXIT_FAILURE,
	"before_USING_block",
	"ContextHasNotBegunYet"
){

	char * tmp;

	printf("before_CONTEXT_BEGIN\n");

	e4c_context_begin(e4c_true, e4c_print_exception);

	printf("before_CONTEXT_END\n");

	e4c_context_end();

	printf("before_USING_block\n");

	using(buffer, tmp, (256) ){

		printf("inside_USING_block\n");

	}

	printf("after_USING_block\n");

	return(EXIT_SUCCESS);
}