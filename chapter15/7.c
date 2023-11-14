#include<stdio.h>
#include<string.h>

#define MAX_LINE_LENGHT 256
#define MAX_FILE_NAME_LENGHT 20

int saveTextToFile(const char* filename) {
	FILE* fp;

	fopen_s(&fp, filename, "w");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.");
		return -1;
	}

	char buffer[MAX_LINE_LENGHT];
	int lineCount = 0;
	
	while (fgets(buffer, MAX_LINE_LENGHT, stdin) != 0) {
		fputs(buffer, fp);
		lineCount++;
	}

	fclose(fp);
	return 0;
}

int main() {
	char fileName[MAX_FILE_NAME_LENGHT];

	printf("���� �̸��� �Է��Ͻÿ�: ");
	fgets(fileName, MAX_FILE_NAME_LENGHT, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; // ���� ���� ����

	saveTextToFile(fileName);

	return 0;
}