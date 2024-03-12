#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <stdint.h>

#define WIDTH 400
#define HEIGHT 500

typedef struct FrameBuf{
	int width;
	int height;
	uint32_t* vram;
}FrameBuf;

typedef struct Image{
	int width;
	int height;
	uint32_t* pixels;
}Image;

uint32_t RGB_32(unsigned char r, unsigned char g, unsigned char b);
void Fill(uint32_t* buf, int width, int height, uint32_t color);
void SetPixel(Image* image, int x, int y, uint32_t color);
void DrawPixel(uint32_t* vram, int x, int y, uint32_t color);
uint32_t GetPixel(Image* image, int x, int y);
void LoadImg(Image* image, const char* filename);
void DisplayImage(uint32_t* vram, int tx, int ty, uint32_t chromakey, Image* image);

#endif

