# parseopt

Another ANSI C Command Line Option Parsing Library. Features:

  * ANSI C Code that should compile anywhere
  * Similar to GNU getopt
  * Also parses positional arguments
  * MIT licensed

# Example

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

Output:

	$ ./sample -a 12 -b 34 -c56 -fed 78
	Encountered option a at index 1 with argument 12
	Encountered option b at index 3 (no arguments)
	Encountered positional argument '34'
	Encountered option c at index 5 with argument 56
	Encountered option f at index 6 (no arguments)
	Encountered option e at index 6 (no arguments)
	Encountered option d at index 6 (no arguments)
	Encountered positional argument '78'


# License
MIT

