#include <stdio.h>
#include <stdlib.h>
#include "../bin/binary_sort_tree.cpp"
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BinarySortTreePtr Tree=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	int flag =0;
	while (1) {
		printf("[1]��ʼ����                   [2]����ڵ�\n");
		printf("[3]ɾ���ڵ�                   [4]���ҽڵ�����\n");
		printf("[5]�ǵݹ��������             [6]�ݹ��������\n");
		printf("[7]�ǵݹ��������             [8]�ݹ��������\n");
		printf("[9]�ǵݹ�������             [10]�ݹ�������\n");
		printf("[11]�������\n");
		int chk_data(char *num);
		char str[SIZE];
		printf("\n������Ҫִ�еĲ�����Ӧ������:");
		scanf("%s", &str);
		while (chk_data(str) == 0) {
			printf("�����������������:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=12) {
			printf("\nû�ж�Ӧ�Ĳ���\n");
			printf("\n");
			system("pause");
			system("cls");
			continue;
		}
		switch (k) {
			case 1: {
				int chk_data(char *num);
				char str[SIZE];
				printf("��������ڵ�����:");
				scanf("%s", &str);
				while (chk_data(str) == 0) {
					printf("�������ݴ�������������:");
					scanf("%s", &str);
					continue;
				}
				ElemType data=atoi(str);
				BST_init(Tree,data);
				flag=1;
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				if(flag==1) {
					int chk_data(char *num);
					char str[SIZE];
					printf("����������:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("�������ݴ�������������:");
						scanf("%s", &str);
						continue;
					}
					ElemType data=atoi(str);
					BST_insert(Tree->root,data);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				printf("\n�������д������!!!\n");
				printf("�������д������!!!\n");
				printf("�������д������!!!\n");
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				if(flag==1) {
					int chk_data(char *num);
					char str[SIZE];
					printf("������Ҫ���ҵ�����:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("�������ݴ�������������:");
						scanf("%s", &str);
						continue;
					}
					ElemType data=atoi(str);
					BST_search(Tree->root,data);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				if(flag==1) {
					BST_preorderI(Tree->root,printnode);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				if(flag==1) {
					BST_preorderR(Tree->root,printnode);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 7: {
				if(flag==1) {
					BST_inorderI(Tree->root,printnode);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 8: {
				if(flag==1) {
					BST_inorderR(Tree->root,printnode);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 9: {
				if(flag==1) {
					printf("\nд������!!!\n");
					printf("д������!!!\n");
					printf("д������!!!\n");
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 10: {
				if(flag==1) {
					BST_postorderR(Tree->root,printnode);
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 11: {
				if(flag==1) {
					printf("\nд������!!!\n");
					printf("д������!!!\n");
					printf("д������!!!\n");
				} else {
					printf("\nδ��ʼ����\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
