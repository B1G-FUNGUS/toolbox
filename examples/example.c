#include <stdio.h>
#include "clargs.h"
#include "vector.h"

Flag flist[] = {
	{'h', "help", false},
	{'a', "aflag", true},
	{'b', "bflag", false}
};

// Unfortunately, you need to do this in order for two vectors of the same type
// to be treated like they have the same type.
typedef vec(char) cvec;

cvec tostrvec(char *instr) {
	cvec outstr;
	vinit(outstr);
	for (int i = 0; instr[i] != '\0'; i++) {
		append(outstr, instr[i]);
	}
	append(outstr, '\0');
	return outstr;
}

void main(int argc, char *argv[]) {

	// clargs example
	size_t flagc = sizeof(flist)/sizeof(Flag);
	SArgV sargv;
	sargv = mksargs(argc, argv, flist, flagc);

	for (size_t i = 0; i < sargv.length; i++) {
		Arg arg = sargv.v[i];
		if (arg.flag == 'h') {
			for (size_t i = 0; i < flagc; i++) {
				printf("-%c, --%s", flist[i].shortname,
					flist[i].longname);
				if (flist[i].takesarg) printf(" ARG");
				printf("\n");
					
			}
		} else if (arg.flag) {
			if (arg.str != NULL) {
				printf("-%c %s\n", arg.flag, arg.str);
			} else {
				printf("-%c\n", arg.flag);
			}
		} else {
			printf("%s\n", arg.str);
		}
	}
	
	// vector example
	vec(float) fvec;
	vinit(fvec);

	for (int i = 0; i < 30; i++) {
		float result = i/3.0;
		append(fvec, result);
	}

	for (size_t i = 0; i < fvec.length; i++) {
		float output = getelem(fvec, i);
		printf("%f\n", output);
	}

	cvec str = tostrvec("example string");
	printf("%s\n", str.v);

	vfree(fvec);
	vfree(str);

}
