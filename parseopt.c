#include <stdlib.h>
#include <stdio.h>
#include "parseopt.h"


/**
 * Constructor for parse_option objects
 */
parse_option *new_parse_option(char option, char* argument, int index) {
	parse_option *opt = (parse_option *)malloc(sizeof(parse_option));
	if(opt == NULL) {
		perror("Cannot malloc option!");
	}

	opt->option = option;
	opt->argument = argument;
	opt->index = index;
	opt->next = NULL;

	return opt;
}

/**
 * Find the index of an option character opt in the options definition options
 */
int findopt(char opt, const char* options) {
	int opti;
	opti = 0;

	while((options[opti] != 0) && (options[opti] != opt)) { opti++; }
	return opti;
}

/**
 * Parse an array of command line arguments
 */
parse_option *parseopt(int argc, char *argv[], const char *options) {
	int argi, argii, opti;
	const char *arg;

	parse_option *head, *tail, *newopt;

	argi = 1;

	head = NULL;
	tail = NULL;

	
	while(argi < argc) {
		arg = argv[argi];

		if(arg[0] == '-') {

			argii = 1;

			while(arg[argii] != 0) {

				opti = findopt(arg[argii], options);
				if(options[opti] == 0) {
					printf("Unknown option %c at argument index %d\n", arg[argii], opti);
					return NULL;
				}

				if(options[opti+1] == ':') {
					newopt = new_parse_option(options[opti], argv[argi+1], argi);
					argi++;
				} else {
					newopt = new_parse_option(options[opti], NULL, argi);
				}

				if(head == NULL) {
					head = tail = newopt;
				} else {
					tail->next = newopt;
					tail = newopt;
				}

				argii++;
			}

		} else {

			newopt = new_parse_option(0, argv[argi], argi);

			if(head == NULL) {
				head = tail = newopt;
			} else {
				tail->next = newopt;
				tail = newopt;
			}

		}

		argi++;
	}


	return head;
}

