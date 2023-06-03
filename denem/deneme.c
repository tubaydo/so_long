#include "mini/mlx.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;
    void	*mlx;
	void	*img;
	char	*relative_path = "./tuba.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
 