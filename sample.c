#include <stdio.h>
#include <stdlib.h>
#include "parseopt.h"


int main(int argc, char *argv[]) {

	parse_option *opts, *opt;
	
	opts = parseopt(argc, argv, "a:bc:def?");

	while(opts != NULL) {
		opt = opts;
		opts = opts->next;


		switch(opt->option) {

			case 'a':
			case 'c':
				printf("Encountered option %c at index %d with argument %s\n", opt->option, opt->index, opt->argument);
				break;

			case 'b':
			case 'd':
			case 'e':
			case 'f':
				printf("Encountered option %c at index %d (no arguments)\n", opt->option, opt->index);
				break;

			case 0:
				printf("Encountered positional argument '%s'\n", opt->argument);
				break;

			default:
				printf("Unknwon option: %c\n", opt->option);
		}


		free(opt);
	}


	return 0;

}
