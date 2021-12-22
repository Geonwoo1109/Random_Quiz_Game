#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <list>

#define MAX 10 //최대 문재 갯수 

char *txt[10][100] = { NULL, };

char Q_arr[MAX][100], A_arr[MAX][6][100];
int i, j, Q_number;

std :: list<int> Q_index;

main() {

	FILE *Q_file = fopen("Questions.txt", "r");
	if (Q_file == NULL) return;
	
	fscanf(Q_file, "문제 갯수: %d", &Q_number);
	printf("문제 갯수: %d", Q_number);
	
    
    
    for (i=0; i<=Q_number; i++) {
    	char *str = fgets(Q_arr[i], 100, Q_file);
    	
    	char *ptr = strtok(Q_arr[i], ",");
    	for (j=0; j<10; j++) {
    		
    		if (ptr == NULL) break;           // 자른 문자열이 나오지 않을 때까지 반복
       			txt[i][j] = ptr;             // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
        		//i++;                       // 인덱스 증가

        		ptr = strtok(NULL, ",");   // 다음 문자열을 잘라서 포인터를 반환
    		
		}

	}
	
    
    for (i=1; i<=Q_number; i++) {
    	//printf("\n %s\n",  Q_arr[i]);
    	for (j=0; j<6; j++) printf("\n%s", txt[i][j]);
	}
    
	fclose(Q_file);
    return 0;
}
