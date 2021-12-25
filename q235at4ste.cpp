#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <windows.h>

#define MAX 10 //최대 문재 갯수 
#define file_txt "Questions.txt" //확장자 포함 

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
	system("title Geonwoo's 퀴즈게임");
	system("mode con cols=100 lines=30");
	system("color F0");
	system("cls");
	
	gotoxy(37, 2);
	printf("--== 중국어 랜덤퀴즈! ==--");
	
	gotoxy(43, 9);
	printf("문제 개수: %d", Q_number);
	
	gotoxy(29, 13);
	printf("메모장에 저장된 문제가 랜덤하게 나옵니다.");
	
	gotoxy(2, 28);
	printf("Made by Geonwoo_Kim");
	
	gotoxy(85, 28);
	printf("Version.1.0.0");
	
	gotoxy(45, 19);
	printf("시작(s): ");
}

void get_Question() {
	FILE *Q_file = fopen(file_txt, "r");
	if (Q_file == NULL) return;
	
	fscanf(Q_file, "문제 갯수: %d", &Q_number);
    
    for (i=0; i<=Q_number; i++) {
    	char *str = fgets(Q_arr[i], 100, Q_file);
    	
    	char *ptr = strtok(Q_arr[i], ",");
    	for (j=0; j<10; j++) {
    		
    		if (ptr == NULL) break;           // 자른 문자열이 나오지 않을 때까지 반복
       		txt[i][j] = ptr;             // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
        		

        	ptr = strtok(NULL, ",");   // 다음 문자열을 잘라서 포인터를 반환
    		
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
	
	printf("남은 문제: %d\n", Q_number);
	srand(time(NULL));
	
	/*
	printf("\n");
	for (i=1; i<=100; i++) printf("%d", rand() % Q_number);
	*/
	
	//문제 번호 지정 
	for (i=0; i<5; i++) printf("%d, ", Q_index_arr[i]);
	int a = Q_number-1;
	int temp = rand() % a;
    index = Q_index_arr[temp];
	printf("\n%d -- %d\n", temp, index);         //고쳐야함 Q_index_arr
    printf("Q.%s\n\n", txt[index+1][0]);
    
    //비복원추출 
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
		printf("정답입니다!");
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
		printf("오답입니다!");
	}
	
	
	
	set_index_arr();
	
	
} }
