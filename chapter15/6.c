#include<stdio.h>
#include<ctype.h>

#define MAX_FILE_NAME_LENGHT 20

int countPrintableCharacter(const char* fileName) {
	FILE* fp;

	fopen_s(&fp, fileName, "r");

	if (fp == NULL) {
		printf("파일을 열 수 없습니다. ");
		return -1;
	}

	int countCharacter = 0;
	int  c;
	
	while ((c = getc(fp)) != EOF) {
		if (isprint(c) != 0)
			countCharacter++;
	}

	fclose(fp);
	return countCharacter;
}

int main() {
	char fileName[MAX_FILE_NAME_LENGHT];

	printf("파일 이름을 입력하시오: ");
	fgets(fileName, MAX_FILE_NAME_LENGHT, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; // 개행 문자 제거

	printf("문자의 개수는 %d\n",countPrintableCharacter(fileName));

	return 0;
}