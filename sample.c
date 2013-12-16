#include <stdio.h>
#include <stdlib.h>
#include "parseopt.h"


int main(int argc, char *argv[]) {

	parse_option *opts, *opt;
	
	opts = parseopt(argc, argv, "a:bc:def?");

	while(opts != NULL) {
		opt = opts;
		opts = opts->next;

		if(opt->option != 0) {

			printf("Option: -%c index %d, ", opt->option, opt->index);
			
			if(opt->argument == NULL) {
				printf("No argument\n");
			} else {
				printf("Argument '%s'\n", opt->argument);
			}

		} else {
			printf("Argument: %s\n", opt->argument);
		}

		free(opt);
	}


	return 0;

}
