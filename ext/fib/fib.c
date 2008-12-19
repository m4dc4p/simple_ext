// Include the Ruby headers and goodies
#include "ruby.h"
#include "Test_stub.h"
#include <stdio.h>

// Defining a space for information and references about the module to be stored internally
VALUE MyTest = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
void Init_fib();

// Prototype for our method 'test1' - methods are prefixed by 'method_' here
VALUE method_test1(VALUE self);

// The initialization method for this module
void Init_fib() {
  hs_init(0, 0);

	MyTest = rb_define_module("MyTest");
	rb_define_method(MyTest, "test1", method_test1, 0);
}

// Our 'test1' method.. it simply returns a value of '10' for now.
VALUE method_test1(VALUE self) {
	int x = fibonacci_hs(42);
	return INT2NUM(x);
}

/*int main(int argc, char *argv[]) {
  int i;
  hs_init(&argc, &argv);
 
  i = fibonacci_hs(42);
  printf("Fibonacci: %d\n", i);
 
  hs_exit();
  return 0;
}
*/
