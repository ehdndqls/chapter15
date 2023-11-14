#include<stdio.h>
#include<stdlib.h>

#define MAX_FILE_NAME_LENGHT 20
#define MAX_FILE_LENGHT 20
#define MAX_LINE_LENGHT 256

void mergeFiles(const char* file1, const char * file2,const char *mergefile) {
	FILE* src1;
	FILE* src2;
	FILE* dst;

	fopen_s(&src1, file1, "r");
	fopen_s(&src2, file2, "r");
	fopen_s(&dst, mergefile, "w");

	if (src1 == NULL || src2 == NULL || dst == NULL) {
		printf("������ �� �� �����ϴ�. \n");
		return -1;
	}

	char buffer[MAX_LINE_LENGHT];

	while (fgets(buffer, MAX_LINE_LENGHT, src1) != NULL) {
		fputs(buffer, dst);
	}
	while (fgets(buffer, MAX_LINE_LENGHT, src2) != NULL) {
		fputs(buffer, dst);
	}

	fclose(src1);
	fclose(src2);
	fclose(dst);
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		printf("�߸��� �����Դϴ�. ����: ���α׷��� ����1 ����2 ����������\n");
		return 1;
	}

	const char* file1 = argv[1];
	const char* file2 = argv[2];
	const char* mergedFile = argv[3];

	mergeFiles(file1, file2, mergedFile);

	return 0;
}