#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_sort_tree.h"

//���������������ͺͳ����Ƿ���ȷ
int chk_data(char *num) {
	int i;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] > '9' || num[i] < '0') {
			printf("\n����ֵ���з���ֵ\n");
			return 0;
		}
	}
	if (i > 10) {
		printf("\n���������ֳ���\n");
		return 0;
	}
	return 1;
}

//��ӡ
void printnode(NodePtr N) {
	printf(" %d ",N->value);
}

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr T,ElemType data) {
	T->root=(NodePtr)malloc(sizeof(Node));
	if(T->root==NULL) {
		printf("�����ڴ�ʧ��");
		return ERROR;
	}
	T->root->value=data;
	T->root->left=NULL;
	T->root->right=NULL;
	printf("\n����ʼ���ɹ�\n");
	return SUCCESS;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr root, ElemType data) {
	NodePtr parentnode;//��¼���ڵ�ָ��
	NodePtr temp=root;//��ʱָ��
	if(root==NULL) {
		printf("\n��Ϊ��\n");
		return ERROR;
	} else {
		NodePtr node=(NodePtr)malloc(sizeof(Node));
		node->left=NULL;
		node->right=NULL;
		node->value=data;
		while(temp!=NULL) {
			parentnode=temp;
			if(temp->value>data) {
				temp=temp->left;
			} else {
				temp=temp->right;
			}
		}
		if(parentnode->value>data) {
			parentnode->left=node;
		} else {
			parentnode->right=node;
		}
		printf("\n�ڵ����ɹ�\n");
		return SUCCESS;
	}
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(NodePtr root, ElemType data) {
	NodePtr parentnode;//��¼���ڵ�ָ��
	NodePtr temp=root;//��ʱָ��
	if(root==NULL) {
		printf("\n��Ϊ��\n");
		return ERROR;
	} else {

	}
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr node, ElemType data) {
	NodePtr stack[100];
	int topmark=-1;
	NodePtr move=node;

	if(move->value==data) {
		printf("\n�������� %d �Ľڵ�\n",move->value);
		return SUCCESS;
	} else if(move->value>data) {
		move=move->left;
		if(move==NULL) {
			printf("\n������������ %d �Ľڵ�\n",data);
			return ERROR;
		} else if(move->value==data) {
			printf("\n������Ϊ %d �Ľڵ�\n",move->value);
			return SUCCESS;
		} else {
			BST_search(move,data);
		}
	} else if(move->value<data) {
		move=move->right;
		if(move==NULL) {
			printf("\n������������ %d �Ľڵ�\n",data);
			return ERROR;
		} else if(move->value==data) {
			printf("\n������Ϊ %d �Ľڵ�\n",move->value);
			return SUCCESS;
		} else {
			BST_search(move,data);
		}
	} else {
		printf("\n������������ %d �Ľڵ�\n",data);
		return ERROR;
	}
}

/**
 * BST preorder traversal without recursion�ǵݹ��������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr node, void (*visit)(NodePtr)) {
	if(node==NULL) {
		printf("\n��Ϊ��\n");
		return ERROR;
	}

	NodePtr stack[100];
	int topmark=-1;
	NodePtr move=node;

	while(move||topmark!=-1) {
		while(move) {
			visit(move);
			stack[++topmark]=move;
			move=move->left;
		}
		if(topmark!=-1) {
			move=stack[topmark];
			topmark--;
			move=move->right;
		}
	}
	return SUCCESS;
}

/**
 * BST preorder traversal with recursion�ݹ��������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr node, void (*visit)(NodePtr)) {
	if(node==NULL) {
		return ERROR;
	}
	visit(node);
	BST_preorderR(node->left,visit);
	BST_preorderR(node->right,visit);
	return SUCCESS;
}



/**
 * BST inorder traversal without recursion�ǵݹ��������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr node, void (*visit)(NodePtr)) {
	if(node==NULL) {
		printf("\n��Ϊ��\n");
		return ERROR;
	}

	NodePtr stack[100];
	int topmark=-1;
	NodePtr move=node;

	while(move||topmark!=-1) {
		while(move) {
			stack[++topmark]=move;
			move=move->left;
		}
		if(topmark!=-1) {
			move=stack[topmark];
			topmark--;
			visit(move);
			move=move->right;
		}
	}
	return SUCCESS;
}

/**
 * BST inorder traversal with recursion�ݹ��������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr node, void (*visit)(NodePtr)) {
	if(node==NULL) {
		return ERROR;
	}
	BST_inorderR(node->left,visit);
	visit(node);
	BST_inorderR(node->right,visit);
	return SUCCESS;


}

/**
 * BST postorder traversal without recursion�ǵݹ�������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr node, void (*visit)(NodePtr)) {
	if(node==NULL) {
		printf("\n��Ϊ��\n");
		return ERROR;
	}

	NodePtr stack[100];
	int topmark=-1;
	NodePtr move=node;

	while(move||topmark!=-1) {
		while(move) {
			stack[++topmark]=move;
			move=move->left;
		}
		if(topmark!=-1) {
			move=stack[topmark];
			topmark--;
			visit(move);
			move=move->right;
		}
	}
	return SUCCESS;
}

/**
 * BST postorder traversal with recursion�ݹ�������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr node, void (*visit)(NodePtr)) {
	if(node==NULL) {
		return ERROR;
	}
	BST_postorderR(node->left,visit);
	BST_postorderR(node->right,visit);
	visit(node);
	return SUCCESS;
}

/**
 * BST level order traversal�������
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr));
