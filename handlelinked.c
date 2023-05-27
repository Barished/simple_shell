#include "shell.h"

/**
 * addNode - adds a node to the start of the list
 * @head: address of pointer to head node
 * @s: str field of node
 * @n: node index used by history
 * Return: size of list
 */
list_t *addNode(list_t **head, const char *s, int n)
{
	list_t *currenthead;

	if (!head)
	{
		return (NULL);
	}
	currenthead = malloc(sizeof(list_t));
	if (!currenthead)
	{
		return (NULL);
	}
	_memset((void *)currenthead, 0, sizeof(list_t));
	currenthead->n = n;
	if (s)
	{
		currenthead->s = _strdup(s);
		if (!currenthead->s)
		{
			free(currenthead);
			return (NULL);
		}
	}
	currenthead->next = *head;
	*head = currenthead;
	return (currenthead);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @s: str field of node
 * @n: node index used by history
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *s, int n)
{
	list_t *new_node, *node;

	if (!head)
	{
		return (NULL);
	}
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
	{
		return (NULL);
	}
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->n = n;
	if (s)
	{
		new_node->s = _strdup(s);
		if (!new_node->s)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new_node;
	}
	else
	{
		*head = new_node;
	}
	return (new_node);
}

/**
 * printstrList - prints only the str element of a list_t linked list
 * @hnde: pointer to first node
 *
 * Return: size of list
 */
size_t printstrList(const list_t *hnde)
{
	size_t j = 0;

	while (hnde)
	{
		_puts(hnde->s ? hnde->s : "(nil)");
		_puts("\n");
		hnde = hnde->next;
		j++;
	}
	return (j);
}

/**
 * _indexdelnode - deletes node at given index
 * @head: address of pointer to first node
 * @ind: index of node to delete
 * Return: 1 on success, 0 on failure
 */
int _indexdelnode(list_t **head, unsigned int ind)
{
	list_t *node, *prev_node;
	unsigned int j = 0;

	if (!head || !*head)
	{
		return (0);
	}
	if (!ind)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (j == ind)
		{
			prev_node->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		j++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * _freeList - frees all nodes of a list
 * @headpt: address of pointer to head node
 * Return: void
 */
void _freeList(list_t **headpt)
{
	list_t *node, *next_node, *head;

	if (!headpt || !*headpt)
	{
		return;
	}
	head = *headpt;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->s);
		free(node);
		node = next_node;
	}
	*headpt = NULL;
}
