#include<iostream>
#include<assert.h>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


typedef struct TreeNode TreeNode;
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
typedef TreeNode* DataType;
typedef struct QueueNode
{
	DataType data;
	struct QueueNode *next;
}Node;

typedef struct Queue
{
	Node *front;
	Node *back;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, DataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// ��β�����
void QueuePush(Queue* q, DataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (q->back == NULL)
	{
		q->front = q->back = node;
	}
	else
	{
		q->back->next = node;
		q->back = node;
	}

}
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->back = NULL;
	}
	else
	{
		Node *next = q->front->next;
		free(q->front);
		q->front = next;
	}
}


// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;

}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->front)
	{
		Node* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
void reverse(int *a, int left, int right)
{
	while (left<right)
	{
		int num = a[left];
		a[left] = a[right];
		a[right] = num;
		left++;
		right--;
	}
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	int curnum = 0;
	int nextnum = 0;
	int arr[1000][500];
	int col[1000];
	int p1 = 0, p2 = 0;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	curnum++;
	col[p1++] = 1;

	while (!QueueEmpty(&q))
	{
		if (curnum == 0)
		{
			curnum = nextnum;
			nextnum = 0;
			col[p1++] = curnum;
			p2 = 0;
		}
		TreeNode* front = QueueFront(&q);
		arr[p1 - 1][p2++] = front->val;
		QueuePop(&q);
		curnum--;

		if (front->left)
		{
			QueuePush(&q, front->left);
			nextnum++;
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
			nextnum++;
		}
	}
	*returnColumnSizes = (int*)malloc(sizeof(int)*p1);
	int **a = (int**)malloc(sizeof(int*)*p1);
	memcpy(*returnColumnSizes, col, sizeof(int)*p1);
	for (int i = 0; i<p1; i++)
	{
		if (i % 2 != 0)
		{
			reverse(arr[i], 0, returnColumnSizes[0][i] - 1);
		}
		a[i] = (int*)malloc(sizeof(int)*returnColumnSizes[0][i]);
		memcpy(a[i], arr[i], sizeof(int)*returnColumnSizes[0][i]);
	}
	*returnSize = p1;
	return a;

}