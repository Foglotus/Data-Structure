#include <stdio.h>
#include <stdlib.h>
typedef struct SqString {
	char *data;
	int size;
	int length;
}SqString;

int InitSqString(SqString *s) {
	s->data = (char *)malloc(sizeof(char) * 20);
	s->size = 20;
	s->length = 0;
	return 1;
}
int AssignSqString(SqString *s, char *str) {
	while (*str != '\0' && s->length < s->size) {
		s->data[s->length++] = *str++;
	}

	if (s->length != s->size)s->data[s->length] = '\0';
	return 1;
}
void PrintSqString(SqString *s) {
	printf("string[%d](%d)=%s\n", s->size, s->length, s->data);
}

void MaxComStr(SqString *s1, SqString *s2, int *index, int *length) {
	int s1_out = 0, s1_inner = 0, s2_inner = 0, s2_out = 0;
	int s1_length = s1->length, s2_length = s2->length;
	int model = 0;
	int max = 0, temp = 0;

	while (s1_length >0) {
		while (s2_inner <s2_length) {
			if (s1->data[s1_inner] == s2->data[s2_inner]) {
				if (model == 0) {
					temp = s1_out;
					s2_out = s2_inner;
				}
				max++;
				s1_inner++;
				s2_inner++;
				model = 1;
			}
			else if (model == 1) {
				if (*length < max) {
					*length = max;
					*index = temp;
				}
				max = 0;
				s2_inner = s2_out + 1;
				s1_inner = s1_out;
				model = 0;

			}
			else {
				s2_inner++;
			}
		}
		if (model == 1) {
			if (*length < max) {
				*length = max;
				*index = s2_out;
				model = 0;
			}
			max = 0;
		}
		s1_out++;
		s1_inner = s1_out;
		s2_inner = s2_out = 0;
		s1_length--;
	}
}

int main()
{
	SqString s1;
	SqString s2;

	InitSqString(&s1);
	InitSqString(&s2);

	AssignSqString(&s1, "owejroiwe");
	AssignSqString(&s2, "weoriwejuoi");

	PrintSqString(&s1);
	PrintSqString(&s2);

	int index = 0, length = 0;
	MaxComStr(&s1, &s2, &index, &length);
	printf("%d %d", index + 1, length);
	getchar();
	return 0;
}
