#include "../includes/fdf.h"

// void		img_pixel_put(t_image *img, int x, int y, int color)
// {
// 	int pix;

// 	pix = (y * img->width) + x;
// 	printf(P_RD"pix = (%d * %d) + %d = %d\n", y, img->width, x, pix);
// 	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
// 		img->data[pix] = color;
// }

// t_image			*make_image(t_bigstruct mr_struct)
// {
// 	t_image	*img = NULL;

// 	img->width = WINDOW_W;
// 	img->height = WINDOW_H;

// 	img->ptr = mlx_new_image(mr_struct.mlx, img->width, img->height);
// 	if (img->ptr == NULL)
// 		error("image problem\n");

// 	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
// 		&img->size_line, &img->endian);
// 	printf(P_BL"bpp: %d\n"P_X, img->bpp);
// 	return (img);
// }

void	clear_image(t_im *image)
{
	ft_bzero(image->pixels, WINDOW_W * WINDOW_H * sizeof(image->pixels[0]));
}

void	drawpixel(t_im *im, int x, int y, int color)
{
	int pix;

	pix = (y * WINDOW_W) + x;
	if (x >= 0 && x < WINDOW_W && y >= 0 && y < WINDOW_H)
		im->pixels[pix] = color;
}

t_im *img_factory(void *mlx)
{
	int		bwoop = 0;
	t_im	*image;

	if (!(image = malloc(sizeof(t_im *))))
		error("not enough memory.\n");
	image->imptr = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	image->pixels = (int *)mlx_get_data_addr(image->imptr, &bwoop, &bwoop, &bwoop);
	
	return (image);
	// mr_struct.pixels[pix(200, 200)] = 0xFFFFFF;
	//mlx_put_image_to_window(mr_struct.mlx, mr_struct.window, mr_struct.image, 0, 0);
}