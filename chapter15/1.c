#include<stdio.h>
#include<string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_LENGTH 20

int compareTextFiles(const char* filename1, const char* filename2) {
	FILE* fp1;
	FILE* fp2;

	fopen_s(&fp1, filename1, "r");
	fopen_s(&fp2, filename2, "r");

	if (fp1 == NULL || fp2 == NULL) {
		printf("파일을 열 수 없습니다.");
		return -1;
	}

	char line1[MAX_LINE_LENGTH];
	char line2[MAX_LINE_LENGTH];
	int lineCount = 1;

	while (fgets(line1, MAX_LINE_LENGTH, fp1) && fgets(line2, MAX_LINE_LENGTH, fp2)) {
		if (strcmp(line1, line2)) {
			printf("두 파일은 서로 다릅니다. \n");
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
		lineCount++;
	}

	if (fgets(line1, MAX_LINE_LENGTH,fp1) || fgets(line2, MAX_LINE_LENGTH, fp2)) {
		printf("두 파일은 서로 다릅니다.\n");
		fclose(fp1);
		fclose(fp2);
		return 0;
	}

	printf("두 파일은 서로 같습니다. \n");
	fclose(fp1);
	fclose(fp2);
	return 1;
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

	compareTextFiles(file1, file2);

	return 0;
}