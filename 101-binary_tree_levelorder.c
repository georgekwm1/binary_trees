#include <stdlib.h>
#include "binary_trees.h"

/* Structure for a node in the queue */
typedef struct queue_node
{
    const binary_tree_t *node;
    struct queue_node *next;
} queue_node_t;

/* Structure for the queue */
typedef struct binary_tree_queue
{
    queue_node_t *front;
    queue_node_t *rear;
} binary_tree_queue_t;

/* Enqueue a node in the queue */
void enqueue(binary_tree_queue_t **queue, const binary_tree_t *node)
{
    /* Create a new node for the queue */
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (new_node == NULL)
        return; /* Handle memory allocation failure */

    new_node->node = node;
    new_node->next = NULL;

    /* If the queue is empty, set both front and rear to the new node */
    if ((*queue)->rear == NULL)
    {
        (*queue)->front = (*queue)->rear = new_node;
        return;
    }

    /* Otherwise, add the new node at the end of the queue and update rear */
    (*queue)->rear->next = new_node;
    (*queue)->rear = new_node;
}

/* Dequeue a node from the queue */
const binary_tree_t *dequeue(binary_tree_queue_t **queue)
{
    /* If the queue is empty, return NULL */
    if ((*queue)->front == NULL)
        return NULL;

    /* Get the front node and update front to the next node */
    queue_node_t *front_node = (*queue)->front;
    (*queue)->front = (*queue)->front->next;

    /* If front becomes NULL, update rear to NULL as well */
    if ((*queue)->front == NULL)
        (*queue)->rear = NULL;

    const binary_tree_t *dequeued_node = front_node->node;
    free(front_node);

    return dequeued_node;
}

/* Level-order traversal of binary tree */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Initialize a queue for level-order traversal */
    binary_tree_queue_t *queue = malloc(sizeof(binary_tree_queue_t));
    if (queue == NULL)
        return; /* Handle memory allocation failure */

    queue->front = queue->rear = NULL;

    /* Enqueue the root node */
    enqueue(&queue, tree);

    while (queue->front != NULL)
    {
        /* Dequeue a node and perform the given function */
        const binary_tree_t *current = dequeue(&queue);
        func(current->n);

        /* Enqueue the left child if exists */
        if (current->left != NULL)
            enqueue(&queue, current->left);

        /* Enqueue the right child if exists */
        if (current->right != NULL)
            enqueue(&queue, current->right);
    }

    /* Free the memory allocated for the queue */
    free(queue);
}


