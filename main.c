/* 
 * Program Name: Queue Queues
 * Author: mannuscritto
 * Description: The program makes a queue of queues. Each new item is placed in the appropriate queue based on its value.
 * If the new item does not have a queue for its value, a new queue is created.
 */

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

struct queuesNode *qFront = NULL;
struct queuesNode *qRear = NULL;

void createQueue(int value) {
	struct regularNode *temp = (struct regularNode *)malloc(sizeof(struct regularNode));
	temp->value = value;
	temp->pointer = NULL;
	struct queuesNode *qTemp = (struct queuesNode *)malloc(sizeof(struct queuesNode));
	qTemp->front = temp;
	qTemp->rear = temp;
	if (qFront == NULL && qRear == NULL) {
		qFront = qRear = qTemp;
		return;
	}		
	qRear->pointer = qTemp;
	qRear = qTemp;
}

void put(int value) {
	struct queuesNode *qTemp = qFront;
	struct regularNode *temp = (struct regularNode *)malloc(sizeof(struct regularNode));
	temp->value = value;
	temp->pointer = NULL;
	if (qTemp == NULL) {
		createQueue(value);
		return;
	}
	while (qTemp != NULL) {
		if (qTemp->rear->value == value) {
			qTemp->rear->pointer = temp;
			qTemp->rear = temp;
			return;
		}
		if (qTemp->pointer == NULL) {
			createQueue(value);
			return;
		}
		qTemp = qTemp->pointer;
	}
}

int get() {
	struct queuesNode *qTemp = qFront;
	if (qTemp == NULL) {
		printf("\nImposs�vel remover item! N�o h� filas!\n");
		return -1;
	} else {
		struct regularNode *temp = qTemp->front;
		int value = qTemp->front->value;
		qTemp->front = qTemp->front->pointer;
		free(temp);
		if (qTemp->front == NULL) {
			qFront = qFront->pointer;
			free(qTemp);
			if (qFront == NULL) {
				qRear = NULL;
			}
		}
		return value;
	}
}

void display() {
	struct queuesNode *qTemp = qFront;
	if (qTemp == NULL) {
		printf("\nN�o h� filas a serem imprimidas!\n");
		return;
	}
	while (qTemp != NULL) {
		struct regularNode *temp = qTemp->front;
		printf("\nElementos de uma fila: \n|");
		while (temp != NULL) {
			printf(" %d |", temp->value);
			temp = temp->pointer;
		}
		printf("\n");
		qTemp = qTemp->pointer;
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int opt, value;
	while (1) {
		system("cls");
		printf("MENU DA FILA COM PONTEIROS\n\n");
		printf("\tInserir Item_____[1]\n");
		printf("\tRemover Item_____[2]\n");
		printf("\tImprimir Filas___[3]\n");
		printf("\tSair_____________[0]\n");
		do {
			printf("Digite a op��o: ");
			scanf("%d", &opt);
		} while(opt < 0 || opt > 3);
		switch (opt) {
			case 1:
				do {
					printf("Digite o valor do item: ");
					scanf("%d", &value);
				} while(value < 0);
				put(value);
				break;
			case 2:
				value = get();
				if (value >= 0) {
					printf("\nO valor do item removido � %d\n", value);
				}
				break;
			case 3:
				display();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nOp��o Inv�lida!\n");
		}
		system("pause");
	}
	return 0;
}
