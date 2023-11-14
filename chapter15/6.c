#include<stdio.h>
#include<ctype.h>

#define MAX_FILE_NAME_LENGHT 20

int countPrintableCharacter(const char* fileName) {
	FILE* fp;

	fopen_s(&fp, fileName, "r");

	if (fp == NULL) {
		printf("������ �� �� �����ϴ�. ");
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

	printf("���� �̸��� �Է��Ͻÿ�: ");
	fgets(fileName, MAX_FILE_NAME_LENGHT, stdin);
	fileName[strcspn(fileName, "\n")] = '\0'; // ���� ���� ����

	printf("������ ������ %d\n",countPrintableCharacter(fileName));

	return 0;
}