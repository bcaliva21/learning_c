#ifndef STRUCTS_H
#define STRUCTS_H

struct run {
	double time;
	int errors;
};

struct user {
    char *name;
	struct run bestRun;
	double bestTime;
	int leastErrors;
	int mostErrors;
};

#endif // STRUCTS_H
