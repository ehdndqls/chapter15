#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_VALUES 100
#define MAX_FILE_NAME_LENGHT 20

int saveTextFile(const char* text, const float* values, int numValues) {
	FILE* file;

	fopen_s(&file, text, "w");

	if (file == NULL) {
		printf("������ �� �� �����ϴ�.");
		return -1;
	}

	for (int i = 0; i < numValues; i++) {
		fprintf(file, "%f\n", values[i]);
	}

	fclose(file);

	return 1;
}

int saveBinaryFile(const char* binary, const float* values, int numValues) {
	FILE* file;

	fopen_s(&file, binary, "wb");

	if (file == NULL) {
		printf("������ �� �� �����ϴ�.");
		return -1;
	}

	for (int i = 0; i < numValues; i++) {
		fprintf(file, "%f\n", values[i]);
	}

	fwrite(values, sizeof(float), numValues, file);

	fclose(file);

	return 1;
}

int main() {
	char file1[MAX_FILE_NAME_LENGHT];
	char file2[MAX_FILE_NAME_LENGHT];

	printf("ù��° ���� �̸�: ");
	fgets(file1, MAX_FILE_NAME_LENGHT, stdin);
	file1[strcspn(file1, "\n")] = '\0'; // ���� ���� ����

	printf("�ι�° ���� �̸�: ");
	fgets(file2, MAX_FILE_NAME_LENGHT, stdin);
	file2[strcspn(file2, "\n")] = '\0'; // ���� ���� ����

	srand((unsigned)time(NULL));

	float values[NUM_VALUES];

	for (int i = 0; i < NUM_VALUES; i++) {
		values[i] = rand();
	}

	saveTextFile(file1, values, NUM_VALUES);
	saveBinaryFile(file2, values, NUM_VALUES);

	return 0;
}