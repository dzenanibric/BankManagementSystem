#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "general.h"
#include "mainFunctions.h"

int main(int argc, char *argv[]) {
	systemAccess();
	startMainProgram();
	return 0;
}
