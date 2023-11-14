#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGHT 256
#define SIZE 20

int searchTextfile(const char* file, char *keyword) {
	FILE* fp;
	
	fopen_s(&fp, file, "r");

	if (fp == NULL) {
		printf("���� ���� ����");
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

	printf("���� �̸�: ");
	fgets(fileName, SIZE, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; //���� ���� ����

	printf("Ž���� �ܾ�: ");
	gets_s(keyword, SIZE);

	searchTextfile(fileName, keyword);

	return 0;
}