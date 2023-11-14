#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE_LENGHT 256
#define MAX_FILE_NAME 20

void insertLineNumbers(const char* file) {
	FILE* fp;
	fopen_s(&fp, file, "r");

	if (fp == NULL) {
		printf("파일을 열 수 없습니다. \n");
		return -1;
	}

	char buffer[MAX_LINE_LENGHT];
	int lineCount = 1;

	while (fgets(buffer, MAX_LINE_LENGHT, fp) != NULL) {
		printf("%6d: %s\n", lineCount, buffer);
		lineCount++;
	}

	fclose(fp);
	return 0;
}

int main() {
	char fileName[MAX_FILE_NAME];

	printf("파일이름을 입력하시오: ");
	fgets(fileName, MAX_FILE_NAME, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; // 개행 문자 제거

	insertLineNumbers(fileName);

	return 0;
}