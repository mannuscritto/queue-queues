#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct regularNode {
	int value;
	struct regularNode *pointer;
};

struct queuesNode {
	struct regularNode *front;
	struct regularNode *rear;
	struct queuesNode *pointer;
};

struct queuesNode *top = NULL;

void createQueue(int value) {
	struct queuesNode *qTemp = (struct queuesNode *)malloc(sizeof(struct queuesNode));
	struct regularNode *temp = (struct regularNode *)malloc(sizeof(struct regularNode));
	temp->value = value;
	temp->pointer = NULL;
	qTemp->front = temp;
	qTemp->rear = temp;
	qTemp->pointer = NULL;
	if (top == NULL) {
		top = qTemp;
		return;
	}
	top->pointer = qTemp;
	top = qTemp;
}

void put(int value) {
	struct queuesNode *qTemp = top;
	struct regularNode *temp = (struct regularNode *)malloc(sizeof(struct regularNode));
	temp->value = value;
	temp->pointer = NULL;
	while (qTemp->pointer != NULL) {
		if (qTemp->rear->value == value) {
			qTemp->rear->pointer = temp;
			qTemp->rear = temp;
			return;
		}
		if (qTemp->pointer == NULL) {
			printf("\nNão há nenhuma fila com esse número!\n");
		}
		qTemp = qTemp->pointer;
	}
}

void display() {
	struct queuesNode *qTemp = top;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int opt, value;
	while (1) {
		system("cls");
		printf("MENU DA FILA COM PONTEIROS\n\n");
		printf("\tCriar Fila_______[1]\n");
		printf("\tInserir Item_____[2]\n");
		printf("\tRemover Item_____[3]\n");
		printf("\tImprimir Filas___[4]\n");
		printf("\tSair_____________[0]\n");
		do {
			printf("Digite a opção: ");
			scanf("%d", &opt);
		} while(opt < 0 || opt > 4);
		switch (opt) {
			case 1:
				do {
					printf("Digite o valor do item: ");
					scanf("%d", &value);
				} while(value < 0);
				createQueue(value);
				break;
			case 2:
				do {
					printf("Digite o valor do item: ");
					scanf("%d", &value);
				} while(value < 0);
				put(value);
				break;
			case 3:
				//get();
				break;
			case 4:
				//display();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nOpção Inválida!\n");
		}
		system("pause");
	}
	return 0;
}
