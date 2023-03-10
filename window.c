#include "fdf.h"
#include <mlx.h>

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void rect(t_data *img, int b, int h, int c_x, int c_y, int spessore)
{
    int o_x = c_x - b/2;
    int o_y = c_y - h/2;
    int tmp_b;
    int tmp_h;

    while (spessore > 0)
    {
        tmp_b = b - spessore;
        tmp_h = h - spessore;
        for (int i = 0; i < tmp_b; i++)
            my_mlx_pixel_put(img, o_x + i, o_y, trgb(0,108,82,12));
        for (int i = 0; i < tmp_h; i++)
            my_mlx_pixel_put(img, o_x + tmp_b, o_y + i, trgb(0,108,82,12));
        for (int i = 0; i < tmp_b; i++)
            my_mlx_pixel_put(img, o_x + tmp_b - i, o_y + tmp_h, trgb(0,108,82,12));
        for (int i = 0; i < tmp_h; i++)
            my_mlx_pixel_put( img, o_x, o_y + tmp_h - i, trgb(0,108,82,12));
        spessore--;
    }
}

void tri(t_data *img, int l, int c_x, int c_y, int spessore)
{
    int o_x;
    int o_y;
    int x;
    int tmp;

    while (spessore > 0)
    {
        tmp = l - spessore;
        o_x = c_x - tmp/2;
        o_y = c_y + tmp * sin(M_PI/3) / 2;
        for (int i = 0; i < tmp; i++)
            my_mlx_pixel_put(img, o_x + i, o_y, trgb(0,192,146,18));
        x = o_x;
        while (x < o_x + tmp/2)
        {
            my_mlx_pixel_put(img, x, o_y - sqrt(3) * (x - o_x), trgb(0,192,146,18));
            x += 1;
        }
        x = o_x + tmp;
        while (x >= c_x)
        {
            my_mlx_pixel_put(img, x, o_y - sqrt(3) * (o_x + tmp - x), trgb(0,192,146,18));
            x -= 1;
        }
        spessore--;
    }
}

void circle(t_data *img, double r, int c_x, int c_y, int spessore)
{
    double  x;
    double  y;
    double  tmp;

    while (spessore > 0)
    {
        tmp = r - spessore;
        x = -tmp;
        while (x <= tmp)
        {
            y = tmp * sin(acos(x / tmp));
            my_mlx_pixel_put(img, c_x + x, c_y + y, trgb(0,152,120,30));
            if ((x >= -tmp && x <= -tmp / 10) || (x <= tmp && x >= tmp / 10))
              x += 0.001;
            else
             x += 1;
        }
        x = tmp;
        while (x >= - tmp)
        {
            y = - tmp * sin(acos(x / tmp));
            my_mlx_pixel_put(img, c_x + x, c_y + y, trgb(0,152,120,30));
            if ((x >= -tmp && x <= - tmp / 10) || (x <= tmp && x >= tmp / 10))
               x -= 0.001;
            else
                x -= 1;
        }
        spessore--;
    }
}

void window(void)
{
    void    *mlx;
    void    *mlx_win;
    //2/3 (500 + l * sin(M_PI/3) / 2)
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
    img.img = mlx_new_image(mlx, 1000, 1000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    rect(&img, 1, 787, 504, 500, 10);
    tri(&img, 923, 500, 500, 20);
    circle(&img, 262, 501, 633, 10);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}