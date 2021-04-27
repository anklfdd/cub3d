#include "cub3d.h"

unsigned char	*createBitmapFileHeader (int height, int stride)
{
	int				fileSize;
	unsigned char	*fileHeader;

	fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);
	fileHeader = (unsigned char *)ft_calloc(FILE_HEADER_SIZE, 1);
	fileHeader[0] = (unsigned char)('B');
	fileHeader[1] = (unsigned char)('M');
	fileHeader[2] = (unsigned char)(fileSize);
	fileHeader[3] = (unsigned char)(fileSize >> 8);
	fileHeader[4] = (unsigned char)(fileSize >> 16);
	fileHeader[5] = (unsigned char)(fileSize >> 24);
	fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (fileHeader);
}

unsigned char	*createBitmapInfoHeader (int height, int width)
{
	static unsigned char	*infoHeader;

	infoHeader = (unsigned char *)ft_calloc(INFO_HEADER_SIZE, 1);
	infoHeader[0] = (unsigned char)(INFO_HEADER_SIZE);
	infoHeader[4] = (unsigned char)(width);
	infoHeader[5] = (unsigned char)(width >> 8);
	infoHeader[6] = (unsigned char)(width >> 16);
	infoHeader[7] = (unsigned char)(width >> 24);
	infoHeader[8] = (unsigned char)(height);
	infoHeader[9] = (unsigned char)(height >> 8);
	infoHeader[10] = (unsigned char)(height >> 16);
	infoHeader[11] = (unsigned char)(height >> 24);
	infoHeader[12] = (unsigned char)(1);
	infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (infoHeader);
}

int	generateBitmapImage (unsigned char *image, int height, int width, char *FileName)
{
	int				widthInBytes;
	unsigned char	*padding;
	int				paddingSize;
	int				stride;
	int				imageFile;
	unsigned char	*fileHeader;
	unsigned char	*infoHeader;
	int				i;


	widthInBytes = width * BYTES_PER_PIXEL;
	padding = (unsigned char *)ft_calloc(BYTES_PER_PIXEL, 1);
    paddingSize = (4 - (widthInBytes) % 4) % 4;
	stride = (widthInBytes) + paddingSize;
	if ((imageFile = open(FileName, O_CREAT|O_RDWR,0777)) == -1)
		return(7);
    fileHeader = createBitmapFileHeader(height, stride);
    write(imageFile, fileHeader, FILE_HEADER_SIZE);
	infoHeader = createBitmapInfoHeader(height, width);
    write(imageFile, infoHeader, INFO_HEADER_SIZE);
	i = height - 1;
	while (i >= 0)
	{
        write(imageFile, (image + (i * widthInBytes)), BYTES_PER_PIXEL * width);
        write(imageFile, padding, paddingSize);
		i--;
	}
	close(imageFile);
	return (0);
}

int				save_bmp(t_map *map)
{
    if (generateBitmapImage((unsigned char*)map->mlx.addr,
	map->win.height, map->win.width, "screen.bmp") == 7)
		return (7);
	return (0);
}
