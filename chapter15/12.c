#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGHT 256
#define SIZE 20

int searchTextfile(const char* file, char *keyword) {
	FILE* fp;
	
	fopen_s(&fp, file, "r");

	if (fp == NULL) {
		printf("파일 열기 실패");
		return -1;
	}

	char buffer[MAX_LINE_LENGHT];
	int lineCount = 1;

	while (fgets(buffer, MAX_LINE_LENGHT, fp) != NULL) {
		if (strstr(buffer, keyword) != NULL) {
			printf("%s %d : %s\n", file, lineCount, buffer);
		}
		lineCount++;
	}
	fclose(fp);
	return 0;
}

int main() {
	char fileName[SIZE];
	char keyword[SIZE];

	printf("파일 이름: ");
	fgets(fileName, SIZE, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; //개행 문자 제거

	printf("탐색할 단어: ");
	gets_s(keyword, SIZE);

	searchTextfile(fileName, keyword);

	return 0;
}