#include "gctruck.h"

typedef struct {
	char name[30];
	char age;
} human_t;

int main() {
	GCNEW(h1, human_t);
	GCNEW(h2, human_t);
	GCNEW(h3, human_t);

	return 0;
}