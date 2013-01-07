int cmd_say_vasea(char * vidmem, int position) {

	char * msg = (char *) "Vasea";
	position = puts(msg, vidmem, position);

	return position;
}