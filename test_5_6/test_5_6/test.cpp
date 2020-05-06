
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode BTNode;
typedef BTNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode *next;
}Node;

typedef struct Queue
{
	Node *front;
	Node *back;
}Queue;
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, QDataType data)
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
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// 队头出队列
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


// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;

}
// 销毁队列
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

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* levelOrder(struct TreeNode* root, int* returnSize){
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	int *arr = (int*)malloc(sizeof(int)* 10000);
	int index = 0;

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);
		arr[index++] = front->val;
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
	*returnSize = index;
	return arr;

}