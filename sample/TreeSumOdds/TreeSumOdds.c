
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

static int findOdd(int sum, Tree t);

int TreeSumOdds(Tree t) {
	int sum = 0;
	sum += findOdd(sum, t);

	return sum;
}

static int findOdd(int sum, Tree t) {
	if (t == NULL) {
		return sum;
	}
	sum = findOdd(sum, t->right);
	sum = findOdd(sum, t->left);

	int odd = 0;
	if ((t->value % 2 == 1) || (t->value % 2 == -1)) {
		odd = t->value;
	}

	return sum + odd;
}

