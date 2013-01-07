int cmd_greet(char * vidmem, int position, char * args) {

	char * msg = (char *) "Hello, ";
	position = puts(msg, vidmem, position);
	position = puts(args, vidmem, position);

	return position;
}