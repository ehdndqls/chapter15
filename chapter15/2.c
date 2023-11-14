#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_LENGTH 20
#define MAX_LINE_LENGTH 256

int convertTextToUpper(const char* filename1, const char* filename2) {
	FILE* fp1;
	FILE* fp2;

	fopen_s(&fp1, filename1, "r");
	fopen_s(&fp2, filename2, "w");

	if (fp1 == NULL || fp2 == NULL) {
		printf("파일을 열 수 없습니다.");
		return -1;
	}

	char line[MAX_FILE_LENGTH];
	int c;

	while ((c = fgetc(fp1)) != EOF) {
		fputc(toupper(c), fp2);
		printf("%c", toupper(c));
	}
	fclose(fp1);
	fclose(fp2);

	return 1;
}

void printText(file) {
	FILE* fp;
	fopen_s(&fp, file, "w");

	int c;

	while (c = fgetc(fp) != EOF)
		putchar(c);
	
	fclose(fp);

	return 0;
}

int main() {
	char file1[MAX_FILE_LENGTH];
	char file2[MAX_FILE_LENGTH];

	printf("첫 번째 파일 이름: ");
	fgets(file1, MAX_FILE_LENGTH, stdin);
	file1[strcspn(file1, "\n")] = '\0'; // 개행 문자 제거

	printf("두 번째 파일 이름: ");
	fgets(file2, MAX_FILE_LENGTH, stdin);
	file2[strcspn(file2, "\n")] = '\0'; // 개행 문자 제거

	convertTextToUpper(file1, file2);
	printText(file2);

	return 0;
}