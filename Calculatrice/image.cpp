#include "image.h"
#include <cstdio>
#include <cstdlib>

uint32_t RGB_32(unsigned char r, unsigned char g, unsigned char b) {
	uint32_t color = r << 16 | g << 8 | b;
	return color;
}

void DrawPixel(uint32_t* vram, int x, int y, uint32_t color){
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT){
		vram[x + y * WIDTH] = color;
	}
}

void SetPixel(Image* image, int x, int y, uint32_t color){
	if (x >= 0 && y >= 0 && x < image->width && y < image->height){
		image->pixels[x + y * image->width] = color;
	}
}

uint32_t GetPixel(Image* image, int x, int y){
	if (x >= 0 && y >= 0 && x < image->width && y < image->height){
		return image->pixels[x + y * image->width];
	}
}

void Fill(uint32_t* buf, int width, int height, uint32_t color){
	int i;
	for (i = 0; i < width * height; i++){
		buf[i] = color;
	}
}

void DisplayImage(uint32_t* vram, int tx, int ty, uint32_t chromakey, Image* image){
	int x,y;
	for(y = 0; y < image->height; y++){
		for (x = 0; x < image->width; x++) {
			uint32_t color = GetPixel(image, x, y);
			if (color != chromakey){
				DrawPixel(vram, x + tx, y + ty,color);
			}
		}
	}
}

unsigned char ReadByte(FILE* file) {
	unsigned char byte = 0;
	std::fread(&byte, 1, 1, file);
	return byte;
}

unsigned short ReadShort(FILE* file) {
	unsigned short word = 0;
	std::fread(&word, 2, 1, file);
	return word;
}

unsigned long ReadLong(FILE* file) {
	unsigned long dword = 0;
	std::fread(&dword, 4, 1, file);
	return dword;
}

void LoadImg(Image* image, const char* filename) {
	FILE* file;
	errno_t err;

	err = fopen_s(&file, filename, "rb");

	image->width = ReadLong(file);
	image->height = ReadLong(file);

	image->pixels = (uint32_t*)malloc(sizeof(uint32_t) * image->width * image->height);

	int x,y;
	for (y = 0; y < image->height; y++){
		for(x = 0; x < image->width; x++){
			unsigned char r = ReadByte(file);
			unsigned char g = ReadByte(file);
			unsigned char b = ReadByte(file);

			SetPixel(image, x, y, RGB_32(r, g, b));
		}
	}

	fclose(file);
}
