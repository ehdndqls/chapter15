#include<stdio.h>

#define MAX_STUDENT_SIZE 100
#define MAX_NAME_SIZE 10

struct student {
	int kor;
	int eng;
	int math;
	char name[MAX_NAME_SIZE];
}typedef Student;

double calculateAverage(Student s) {
	int sum = s.kor + s.eng + s.math;
	return (double)sum / 3;
}

int convertTextAverage(const char* input, const char* output) {
	FILE* inputFile;
	FILE* outputFile;

	fopen_s(&inputFile, input, "r");
	fopen_s(&outputFile, output, "w");

	if (inputFile == NULL || outputFile == NULL) {
		printf("파일을 열 수 없습니다. ");
		return -1;
	}

	Student s[MAX_STUDENT_SIZE];
	int studentCount = 0;
	char trash[20];
	fscanf_s(inputFile, "%s %s %s %s", trash, 20, trash, 20, trash, 20, trash, 20);
	fprintf(outputFile, "이름 평균\n");

	while ((fscanf_s(inputFile, "%s %d %d %d", s[studentCount].name, MAX_NAME_SIZE, &s[studentCount].kor, &s[studentCount].math, &s[studentCount].eng))!=EOF) {
		fprintf(outputFile, "%6s %4.2lf\n",s[studentCount].name,calculateAverage(s[studentCount]));
		studentCount++;
	}

	fclose(inputFile);
	fclose(outputFile);
	
	return 1;
}

int main() {
	const char* fileName1 = "scores.txt";
	const char* fileName2 = "average.txt";

	convertTextAverage(fileName1, fileName2);

	return 0;
}
