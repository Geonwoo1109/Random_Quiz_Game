#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <list>

#define MAX 10 //�ִ� ���� ���� 

char *txt[10][100] = { NULL, };

char Q_arr[MAX][100], A_arr[MAX][6][100];
int i, j, Q_number;

std :: list<int> Q_index;

main() {

	FILE *Q_file = fopen("Questions.txt", "r");
	if (Q_file == NULL) return;
	
	fscanf(Q_file, "���� ����: %d", &Q_number);
	printf("���� ����: %d", Q_number);
	
    
    
    for (i=0; i<=Q_number; i++) {
    	char *str = fgets(Q_arr[i], 100, Q_file);
    	
    	char *ptr = strtok(Q_arr[i], ",");
    	for (j=0; j<10; j++) {
    		
    		if (ptr == NULL) break;           // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
       			txt[i][j] = ptr;             // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
        		//i++;                       // �ε��� ����

        		ptr = strtok(NULL, ",");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
    		
		}

	}
	
    
    for (i=1; i<=Q_number; i++) {
    	//printf("\n %s\n",  Q_arr[i]);
    	for (j=0; j<6; j++) printf("\n%s", txt[i][j]);
	}
    
	fclose(Q_file);
    return 0;
}
