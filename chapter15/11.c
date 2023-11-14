#include<stdio.h>
#include<string.h>

#define SIZE 100

typedef struct {
	char name[SIZE];
	char author[SIZE];
	char publisher[SIZE];
}book;

book getRecord();
void menu();
void printRecord(FILE*);
void addRecord(FILE*);
void searchRecord(FILE*);
void printData(book);

int main() {
	FILE* fp;

	fopen_s(&fp, "book.dat", "a+");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}

	int select;

	while (1) {
		menu();

		printf("�������� �Է��Ͻÿ�: ");
		scanf_s("%d", &select);

		switch (select) {
		case 1: addRecord(fp); break;
		case 2: printRecord(fp); break;
		case 3: searchRecord(fp); break;
		case 4: fclose(fp); return 0;
		default: break;
		}
	}
}

void menu() {
	printf("====================\n");
	printf("1. �߰�\n2. ���\n3. �˻�\n4. ����\n");
	printf("====================\n");
}

book getRecord() {
	book data;

	rewind(stdin);

	printf("������ �̸�: ");
	gets_s(data.name, SIZE);
	printf("����: ");
	gets_s(data.author, SIZE);
	printf("���ǻ�: ");
	gets_s(data.publisher, SIZE);

	return data;
}

void addRecord(FILE* fp) {
	book data;
	data = getRecord();
	fseek(fp, 1, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
}

void printRecord(FILE*fp) {
	book data;
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		printData(data);
	}
}

void printData(book data) {
	printf("������ �̸�: %s\n����: %s\n���ǻ�: %s\n", data.name, data.author, data.publisher);
}

void searchRecord(FILE* fp) {
	
	char name[SIZE];
	rewind(stdin);
	printf("ã���� �ϴ� ���� �̸�: ");
	gets_s(name, SIZE);

	book data;
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(name, data.name)==0) {
			printData(data);
			break;
		}
	}
}