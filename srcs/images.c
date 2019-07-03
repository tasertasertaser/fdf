#include "../includes/fdf.h"

void		img_pixel_put(t_image *img, int x, int y, int color)
{
 color = 1;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		// img->data = + (int)((x + y * img->width)) = color;
	}
}

t_image			*make_image(t_bigstruct mr_struct)
{
	t_image	*img;

	if (!(img = malloc(sizeof(t_image))))
			error("not enough memory.\n");
	img->width = WINDOW_W;
	img->height = WINDOW_H;
	img->ptr = mlx_new_image(mr_struct.mlx, img->width, img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
		&img->size_line, &img->endian);
	// img->bpp /= 8;
	printf(P_BL"bpp: %d\n"P_X, img->bpp);
	return (img);
}