#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE_LENGHT 256
#define MAX_FILE_NAME 20

void insertLineNumbers(const char* file) {
	FILE* fp;
	fopen_s(&fp, file, "r");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�. \n");
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

	printf("�����̸��� �Է��Ͻÿ�: ");
	fgets(fileName, MAX_FILE_NAME, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; // ���� ���� ����

	insertLineNumbers(fileName);

	return 0;
}