VALUE ensure_func(VALUE obj1)
{
	/* stuff to always run after dangerous_func */
	return obj2;
}

/* wrap rb_ensure so we can rescue an exception */
VALUE begin_func(VALUE dangerous_arg)
{
	return rb_ensure(dangerous_func, dangerous_arg, ensure_func, Qnil);
}

VALUE rescue_func(VALUE obj1)
{
	/* handle exception */
	return obj2;
}

void some_function()
{
	/* ... */

	VALUE result = rb_rescue(begin_func, dangerous_arg, rescue_func, rescue_arg);

	/* ... */
}
