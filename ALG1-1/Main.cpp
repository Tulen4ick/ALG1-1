#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void main() {
	setlocale(LC_ALL, "Rus");
	FILE* fp;
	if ((fp = fopen("1-1.txt", "r")) == NULL)
	{
		printf("Не удалось открыть файл");
		getchar();
		return 0;
	}
	char stack[10];
	int top = -1;
	char buff[100];
	while (fgets(buff, 100, fp) != NULL) {
		printf("%s", &buff);
		int a1, b1;
		a1 = b1 = 0;
		for (int i = 0; i < 100; ++i) {
			if (buff[i] == '(') {
				if (is_full(top) == 0) {
					push(&stack, &top, '(');
				}
				else {
					a1 = 1;
					break;
				}
			}
			if (buff[i] == ')') {
				if (is_empty(top) == 0) {
					pop(&stack, &top);
				}
				else {
					b1 = 1;
					break;
				}
			}
		}
		if ((a1 == 0) && (b1 == 0) && (top == -1)) {
			printf("Выражение корректно\n\n");
		}
		else {
			printf("Выражение некорректно\n");
			if (a1 == 1) {
				printf("Stack Overflow\n");
			}
			if (b1 == 1) {
				printf("Stack Underflow\n");
			}
			printf("\n");
		}
		clear(&top);
		for (int i = 0; i < 100; ++i) {
			buff[i] = '0';
		}
	}
}