#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <windows.h>

#define MAX 10 //�ִ� ���� ���� 
#define file_txt "Questions.txt" //Ȯ���� ���� 

char *txt[10][100] = { NULL, }, Q_arr[MAX][100], A_arr[MAX][6][100], okSign;

int i, j, index, rand_data[10], A_user, Num_correct, Q_number, Q_index_arr[MAX];

std :: list<int> Q_index_list;
std :: list <int> :: iterator p;

void Reset();
void set_index_arr();
void get_Question();
void gotoxy();
void giveQuestion();


main() { while(1) {
	
	get_Question();
	
	//Reset();
	set_index_arr();
	/*
	scanf("%c", &okSign);
	if (okSign != 's') break;
	*/
	
	giveQuestion();
	
	
	//printf("%d", A_user);
	
	
		
    
    /*
    for (i=1; i<=Q_number; i++) {
    	//printf("\n %s\n",  Q_arr[i]);
    	for (j=0; j<6; j++) {
    		printf("\n%s", txt[i][j]);
		}
	}
    */
	int qwer;
	scanf("%d", &qwer);
} }

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void Reset() {
	system("title Geonwoo's �������");
	system("mode con cols=100 lines=30");
	system("color F0");
	system("cls");
	
	gotoxy(37, 2);
	printf("--== �߱��� ��������! ==--");
	
	gotoxy(43, 9);
	printf("���� ����: %d", Q_number);
	
	gotoxy(29, 13);
	printf("�޸��忡 ����� ������ �����ϰ� ���ɴϴ�.");
	
	gotoxy(2, 28);
	printf("Made by Geonwoo_Kim");
	
	gotoxy(85, 28);
	printf("Version.1.0.0");
	
	gotoxy(45, 19);
	printf("����(s): ");
}

void get_Question() {
	FILE *Q_file = fopen(file_txt, "r");
	if (Q_file == NULL) return;
	
	fscanf(Q_file, "���� ����: %d", &Q_number);
    
    for (i=0; i<=Q_number; i++) {
    	char *str = fgets(Q_arr[i], 100, Q_file);
    	
    	char *ptr = strtok(Q_arr[i], ",");
    	for (j=0; j<10; j++) {
    		
    		if (ptr == NULL) break;           // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
       		txt[i][j] = ptr;             // ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
        		

        	ptr = strtok(NULL, ",");   // ���� ���ڿ��� �߶� �����͸� ��ȯ
    		
		}

	}
	for (i=0; i<Q_number; i++) Q_index_list.push_back(i);
	fclose(Q_file);
}

void set_index_arr() {
	
	for (p=Q_index_list.begin(), i=0; p!=Q_index_list.end(); p++, i++) {
		printf("%d", *p);
		Q_index_arr[i] = *p;
	}
	printf("\n");
	for (i=0; i<Q_number; i++) printf("%d", Q_index_arr[i]);
	
}

void giveQuestion() { while(1) {
	
	//system("cls");
	
	printf("���� ����: %d\n", Q_number);
	srand(time(NULL));
	
	/*
	printf("\n");
	for (i=1; i<=100; i++) printf("%d", rand() % Q_number);
	*/
	
	//���� ��ȣ ���� 
	for (i=0; i<5; i++) printf("%d, ", Q_index_arr[i]);
	int a = Q_number-1;
	int temp = rand() % a;
    index = Q_index_arr[temp];
	printf("\n%d -- %d\n", temp, index);         //���ľ��� Q_index_arr
    printf("Q.%s\n\n", txt[index+1][0]);
    
    //�񺹿����� 
    srand(time(NULL));
    for (i=1; i<6; i++) {
    	
    	rand_data[i] = (rand() % 5) + 1;
    	for (int sub_i=0; sub_i<i; sub_i++) {
    		if (rand_data[i] == rand_data[sub_i]) {
    			i--;
    			break;
			}
		}
	}
	//for (i=1; i<=5; i++) printf("%d", rand_data[i]);
	for (i=1; i<=5; i++) printf("%d. %s\n", i, txt[index+1][rand_data[i]]);
	
	scanf("%d", &A_user);
	if (rand_data[A_user] == 1) {
		printf("�����Դϴ�!");
		Num_correct++;
		Q_number--;
		
		p = Q_index_list.begin();
		for (i=0; i<index; i++) {
			//printf("%d", i+100);
			p++;
			//printf("%d", i);
		}
		
		//printf("\n %d %s \n", *p, &p);
		Q_index_list.erase(p);
	} else {
		printf("�����Դϴ�!");
	}
	
	
	
	set_index_arr();
	
	
} }
