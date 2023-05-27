#include "shell.h"

/**
 * _historyFile - gets the history file
 * @info: parameter struct
 * Return: allocated string containg history file
 */

char *_historyFile(info_t *info)
{
	char *buff, *direc;

	direc = _getenv(info, "HOME=");
	if (!direc)
	{
		return (NULL);
	}
	buff = malloc(sizeof(char) * (_strlen(direc) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, direc);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * historyWrite - creates a file, or appends to an existing file
 * @info: the parameter struct
 * Return: 1 on success, else -1
 */
int historyWrite(info_t *info)
{
	ssize_t fd;
	char *filename = _historyFile(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_pstring(node->s, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = _historyFile(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			buildHistory(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		buildHistory(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		_indexdelnode(&(info->history), 0);
	renumberHis(info);
	return (info->histcount);
}

/**
 * buildHistory - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 * Return: Always 0
 */
int buildHistory(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	addEndnode(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumberHis - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 * Return: the new histcount
 */
int renumberHis(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
