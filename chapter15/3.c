#include<stdio.h>
#include<string.h>

#define SIZE 5
#define MAX_FILE_LENGTH 20

int copyBinaryFiles(const char* filename1, const char* filename2) {
	FILE* fp1;
	FILE* fp2;

	fopen_s(&fp1, filename1, "rb");
	fopen_s(&fp2, filename2, "wb");

	if (fp1 == NULL || fp2 == NULL) {
		printf("파일을 열 수 없습니다.");
		return -1;
	}

	int buffer[SIZE];
	size_t bytesRead;

	while ((bytesRead = fread(buffer, sizeof(int), SIZE, fp1)) > 0) {
		fwrite(buffer, sizeof(int), SIZE, fp2);
	}

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

	copyBinaryFiles(file1, file2);

	return 0;
}