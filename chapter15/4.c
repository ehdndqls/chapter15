#include<stdio.h>
#include<string.h>

#define MAX_LINE_LENGHT 256
#define MAX_FILE_NAME_LENGHT 20

int compareTextFiles(const char* fileName1, const char* fileName2) {
	FILE* fp1;
	FILE* fp2;

	fopen_s(&fp1, fileName1, "r");
	fopen_s(&fp2, fileName2, "r");

	if (fp1 == NULL || fp2 == NULL) {
		printf("파일을 열 수 없습니다. ");
		return -1;
	}

	char line1[MAX_LINE_LENGHT];
	char line2[MAX_LINE_LENGHT];
	int lineCount = 1;

	while (fgets(line1, MAX_LINE_LENGHT, fp1) && fgets(line2, MAX_LINE_LENGHT, fp2)) {
		if (strcmp(line1, line2) != 0) {
			printf("%s\n%s", line1, line2);
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
		lineCount++;
	}

	if (fgets(line1, MAX_LINE_LENGHT, fp1)) {
		printf("%s", line1);
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	else if (fgets(line2, MAX_LINE_LENGHT, fp2)) {
		printf("%s", line2);
		fclose(fp1);
		fclose(fp2);
		return 0;
	}

	printf("두 파일은 서로 일치함");
	fclose(fp1);
	fclose(fp2);
	return 1;
}

int main(){
	char file1[MAX_FILE_NAME_LENGHT];
	char file2[MAX_FILE_NAME_LENGHT];

	printf("첫번째 파일 이름: ");
	fgets(file1, MAX_FILE_NAME_LENGHT, stdin);
	file1[strcspn(file1, "\n")] = '\0'; // 개행 문자 제거

	printf("두번째 파일 이름: ");
	fgets(file2, MAX_FILE_NAME_LENGHT, stdin);
	file2[strcspn(file2, "\n")] = '\0'; // 개행 문자 제거

	compareTextFiles(file1, file2);

	return 0;
}