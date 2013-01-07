int cmd_countdown(char * vidmem, int position) {

	char counter = 0x39; // '9' as int
	int i;
	while (counter > 0x2f) {
		position = putc(counter, vidmem, position);
		position = newline(vidmem, position);
		counter--;
		int c, d;
		for ( c = 1 ; c <= 32767 ; c++ )
       		for ( d = 1 ; d <= 1000 ; d++ );
	}
	return position;
}