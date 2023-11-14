#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LANGHT 256

int convertKeyword(const char* originFileName, const char* outputFileName, const char *keyword, const char *newWord) {
	FILE* origin;
	FILE* output;

	fopen_s(&origin, originFileName, "r");
	fopen_s(&output, outputFileName, "w");

	if (origin == NULL || output == NULL) {
		printf("������ �� �� �����ϴ�. ");
		return -1;
	}

	char buf[MAX_LINE_LANGHT];
	char buf2[MAX_LINE_LANGHT] = "";
	char* token; 
	char* context;


	while (fgets(buf, MAX_LINE_LANGHT, origin) != NULL) {
		token = strtok_s(buf, " ",&context);
		while (token != NULL) {
			if (strcmp(token, keyword) == 0) {
				strcat_s(buf2,MAX_LINE_LANGHT, newWord);
				strcat_s(buf2, MAX_LINE_LANGHT, " ");
			}
			else {
				strcat_s(buf2, MAX_LINE_LANGHT, token);
				strcat_s(buf2, MAX_LINE_LANGHT, " ");
			}
			token = strtok_s(NULL, " ",&context);
		}
		fputs(buf2, output);
	}

	fclose(origin);
	fclose(output);

	return 0;
}

int main() {
	char* keyword="Android";
	char* newWord = "�ȵ���̵�";
	char oriFileName[20];
	char outFileName[20];

	printf("�ؽ�Ʈ�����̸�: ");
	fgets(oriFileName, 20, stdin);
	oriFileName[strcspn(oriFileName, "\n")] = '\0'; //���� ���� ����

	printf("��������̸�: ");
	fgets(outFileName, 20, stdin);
	outFileName[strcspn(outFileName, "\n")] = '\0'; //���� ���� ����

	convertKeyword(oriFileName, outFileName, keyword,newWord);

	return 0;
}