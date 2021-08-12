#if 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

const int students = 20;
int main(void)
{
	int i, j, k;
	double kortotal = 0, engtotal = 0, mattotal = 0, koravg = 0, engavg = 0, matavg = 0, tot = 0, avg = 0;
	double kor[students], eng[students], mat[students];

	srand(time(NULL));
	printf("   KOSTA 학생들 국어, 영어, 수학 점수 현황\n================================================\n\n\n");
	for (i = 0; i < students; i++)
	{
		kor[i] = ((rand() % 1000) + 1) / 10.0;  // rand: 난수 발생기 (정수) 0 ~ 100.0   %1000하면 0~999, 1 더해주고 /10
		eng[i] = ((rand() % 1000) + 1) / 10.0;												// 0.1 ~ 100
		mat[i] = ((rand() % 1000) + 1) / 10.0;
		kortotal += kor[i];
		engtotal += eng[i];
		mattotal += mat[i];
		printf("%2d번째 학생 국어점수: %4.1lf  영어점수: %4.1lf  수학점수: %4.1lf  ", i+1, kor[i], eng[i], mat[i]);
		printf("총점: %5.1lf  평균: %4.1lf\n", kor[i] + eng[i] + mat[i], (kor[i] + eng[i] + mat[i]) / 3);
	}
	koravg = kortotal / students;
	engavg = engtotal / students;
	matavg = mattotal / students;
	tot = kortotal + engtotal + mattotal;
	avg = tot / (students * 3);
	printf("국어 총점: %6.1lf, 평균: %4.1lf\n", kortotal, koravg);
	printf("영어 총점: %6.1lf, 평균: %4.1lf\n", engtotal, engavg);
	printf("수학 총점: %6.1lf, 평균: %4.1lf\n", mattotal, matavg);
	printf("전체 총점: %6.1lf, 전체 평균: %4.1lf\n", tot, avg);

	return 0;
}
#endif