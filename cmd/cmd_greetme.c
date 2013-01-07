int cmd_greetme(char * vidmem, int position) {

	char * msg = (char *) "Hello Ana";
	position = puts(msg, vidmem, position);

	return position;
}