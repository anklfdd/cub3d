#include "cub3d.h"

unsigned char	*create_bitmap_file_header (int height, int stride)
{
	int				file_size;
	unsigned char	*file_header;

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);
	file_header = (unsigned char *)ft_calloc(FILE_HEADER_SIZE, 1);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (file_header);
}

unsigned char	*create_bitmap_info_header (int height, int width)
{
	static unsigned char	*info_header;

	info_header = (unsigned char *)ft_calloc(INFO_HEADER_SIZE, 1);
	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(BPP * 8);
	return (info_header);
}

void	generate_bitmap_image(unsigned char *image, int h, int w, char *fn)
{
	unsigned char	*padding;
	int				imageFile;
	unsigned char	*fileHeader;
	unsigned char	*info_header;
	int				i;

	padding = (unsigned char *)ft_calloc(BPP, 1);
	imageFile = open(fn, O_CREAT | O_RDWR, 0777);
	fileHeader = create_bitmap_file_header(h, (w * BPP)
			+ (4 - (w * BPP) % 4) % 4);
	write(imageFile, fileHeader, FILE_HEADER_SIZE);
	info_header = create_bitmap_info_header(h, w);
	write(imageFile, info_header, INFO_HEADER_SIZE);
	i = h - 1;
	while (i >= 0)
	{
		write(imageFile, (image + (i * w * BPP)), BPP * w);
		write(imageFile, padding, (4 - (w * BPP) % 4) % 4);
		i--;
	}
	close(imageFile);
}

void	save_bmp(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.addr = (int *)ft_calloc(map->win.width
			* map->win.height, sizeof(int));
	texture_init(map->wall, &map->tex, &map->mlx);
	ft_rayc(map);
	generate_bitmap_image((unsigned char *)map->mlx.addr,
		map->win.height, map->win.width, "screen.bmp");
	ft_putstr_fd("Скриншот готов\n", 0);
}
