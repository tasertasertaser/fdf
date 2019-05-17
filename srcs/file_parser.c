#include "../includes/fdf.h"

/* THIS IS JUST THE PARSER FROM FILLIT -- NO CHANGES HAVE BEEN MADE
** Control function for all file parsing functions
** Opens & reads file into a buffer of size 545 (max file size + 1)
** Rejects a file if too small or too large
** Calls valid() to check validity of file
** returns list of piece structs
*/

t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	close(fd);
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	buf[bytecount] = '\0';
	if (!valid(buf, bytecount))
		return (NULL);
	return (makelist(buf, bytecount));
}