#include "Bmp.h"
#include <string.h>
#include "../canvas/gl_canvas2d.h"

Bmp::Bmp(const char *fileName, int x, int y)
{
    width = height = 0;
    data = NULL;
    if (fileName != NULL && strlen(fileName) > 0)
    {
        load(fileName);
    }
    else
    {
        printf("Error: Invalid BMP filename");
    }
    this->x = x;
    this->y = y;
}

uchar *Bmp::getImage()
{
    return data;
}

int Bmp::getWidth(void)
{
    return width;
}

int Bmp::getHeight(void)
{
    return height;
}

// M�todo que retorna se as cordenadas do mouse est�o em cima da imagem
bool Bmp::onImage(int mouseX, int mouseY)
{
    if (x <= mouseX && mouseX <= x + width && y <= mouseY && mouseY <= y + height)
    {
        return true;
    }
    return false;
}

void Bmp::render(bool mirror, bool flip, bool grey_scale)
{
    if (data != NULL)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width * 3; j += 3)
            {
                int pos = i * bytesPerLine + j;
                float r = data[pos];
                float g = data[pos + 1];
                float b = data[pos + 2];
                if (grey_scale)
                {
                    float grey = (r + g + b) / 3;
                    r = grey;
                    g = grey;
                    b = grey;
                    CV::color(r, g, b);
                };
                CV::color(r, g, b);
                CV::point(mirror ? x + width - (j / 3) : x + (j / 3), flip ? y + height - i : y + i);
            }
        }
    }
}

void Bmp::convertBGRtoRGB()
{
    unsigned char tmp;
    if (data != NULL)
    {
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width * 3; x += 3)
            {
                int pos = y * bytesPerLine + x;
                tmp = data[pos];
                data[pos] = data[pos + 2];
                data[pos + 2] = tmp;
                r.push_back(data[pos]);
                g.push_back(data[pos + 1]);
                b.push_back(data[pos + 2]);
            }
    }
}

void Bmp::load(const char *fileName)
{
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        printf("\nErro ao abrir arquivo %s para leitura", fileName);
        return;
    }

    printf("\n\nCarregando arquivo %s", fileName);

    // le o HEADER componente a componente devido ao problema de alinhamento de bytes. Usando
    // o comando fread(header, sizeof(HEADER),1,fp) sao lidos 16 bytes ao inves de 14
    fread(&header.type, sizeof(unsigned short int), 1, fp);
    fread(&header.size, sizeof(unsigned int), 1, fp);
    fread(&header.reserved1, sizeof(unsigned short int), 1, fp);
    fread(&header.reserved2, sizeof(unsigned short int), 1, fp);
    fread(&header.offset, sizeof(unsigned int), 1, fp);

    // le o INFOHEADER componente a componente devido ao problema de alinhamento de bytes
    fread(&info.size, sizeof(unsigned int), 1, fp);
    fread(&info.width, sizeof(int), 1, fp);
    fread(&info.height, sizeof(int), 1, fp);
    fread(&info.planes, sizeof(unsigned short int), 1, fp);
    fread(&info.bits, sizeof(unsigned short int), 1, fp);
    fread(&info.compression, sizeof(unsigned int), 1, fp);
    fread(&info.imagesize, sizeof(unsigned int), 1, fp);
    fread(&info.xresolution, sizeof(int), 1, fp);
    fread(&info.yresolution, sizeof(int), 1, fp);
    fread(&info.ncolours, sizeof(unsigned int), 1, fp);
    fread(&info.impcolours, sizeof(unsigned int), 1, fp);

    width = info.width;
    height = info.height;
    bits = info.bits;
    bytesPerLine = (3 * (width + 1) / 4) * 4;
    imagesize = bytesPerLine * height;
    int delta = bytesPerLine - (3 * width);

    printf("\nImagem: %dx%d - Bits: %d", width, height, bits);
    printf("\nbytesPerLine: %d", bytesPerLine);
    printf("\nbytesPerLine: %d", width * 3);
    printf("\ndelta: %d", delta);
    printf("\nimagesize: %d %d", imagesize, info.imagesize);

    if (header.type != 19778)
    {
        printf("\nError: Arquivo BMP invalido");
        getchar();
        exit(0);
    }

    if (width * height * 3 != imagesize)
    {
        printf("\nWarning: Arquivo BMP nao tem largura multipla de 4");
        getchar();
    }

    if (info.compression != 0)
    {
        printf("\nError: Formato BMP comprimido nao suportado");
        getchar();
        return;
    }
    if (bits != 24)
    {
        printf("\nError: Formato BMP com %d bits/pixel nao suportado", bits);
        getchar();
        return;
    }

    if (info.planes != 1)
    {
        printf("\nError: Numero de Planes nao suportado: %d", info.planes);
        getchar();
        return;
    }

    data = new unsigned char[imagesize];
    fseek(fp, header.offset, SEEK_SET);
    fread(data, sizeof(unsigned char), imagesize, fp);

    fclose(fp);
}
