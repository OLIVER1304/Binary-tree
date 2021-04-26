#include <stdio.h>
#include <stdlib.h>
#include "../bin/binary_sort_tree.cpp"
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BinarySortTreePtr Tree=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	int flag =0;
	while (1) {
		printf("[1]初始化树                   [2]插入节点\n");
		printf("[3]删除节点                   [4]查找节点数字\n");
		printf("[5]非递归先序遍历             [6]递归先序遍历\n");
		printf("[7]非递归中序遍历             [8]递归中序遍历\n");
		printf("[9]非递归后序遍历             [10]递归后序遍历\n");
		printf("[11]层序遍历\n");
		int chk_data(char *num);
		char str[SIZE];
		printf("\n请输入要执行的操作对应的数字:");
		scanf("%s", &str);
		while (chk_data(str) == 0) {
			printf("输入错误，请重新输入:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=12) {
			printf("\n没有对应的操作\n");
			printf("\n");
			system("pause");
			system("cls");
			continue;
		}
		switch (k) {
			case 1: {
				int chk_data(char *num);
				char str[SIZE];
				printf("请输入根节点数字:");
				scanf("%s", &str);
				while (chk_data(str) == 0) {
					printf("输入数据错误，请重新输入:");
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
					printf("请输入数据:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("输入数据错误，请重新输入:");
						scanf("%s", &str);
						continue;
					}
					ElemType data=atoi(str);
					BST_insert(Tree->root,data);
				} else {
					printf("\n未初始化树\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				printf("\n这个功能写不出来!!!\n");
				printf("这个功能写不出来!!!\n");
				printf("这个功能写不出来!!!\n");
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				if(flag==1) {
					int chk_data(char *num);
					char str[SIZE];
					printf("请输入要查找的数据:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("输入数据错误，请重新输入:");
						scanf("%s", &str);
						continue;
					}
					ElemType data=atoi(str);
					BST_search(Tree->root,data);
				} else {
					printf("\n未初始化树\n");
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
					printf("\n未初始化树\n");
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
					printf("\n未初始化树\n");
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
					printf("\n未初始化树\n");
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
					printf("\n未初始化树\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 9: {
				if(flag==1) {
					printf("\n写不出来!!!\n");
					printf("写不出来!!!\n");
					printf("写不出来!!!\n");
				} else {
					printf("\n未初始化树\n");
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
					printf("\n未初始化树\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 11: {
				if(flag==1) {
					printf("\n写不出来!!!\n");
					printf("写不出来!!!\n");
					printf("写不出来!!!\n");
				} else {
					printf("\n未初始化树\n");
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
