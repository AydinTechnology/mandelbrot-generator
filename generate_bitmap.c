#include <stdio.h>
#include <stdlib.h>

void produce_bitmap(int size_x, int size_y, unsigned char *data) {
    unsigned char *header = malloc(54);
    int rawimagesize = size_x * size_y * 3;
    int completeimagesize = rawimagesize + 54;
    //file header
    //signature
    header[0] = 0x42;
    header[1] = 0x4d;

    //filesize
    header[2] = (unsigned char)completeimagesize;
    header[3] = (unsigned char)(completeimagesize >> 8);
    header[4] = (unsigned char)(completeimagesize >> 16);
    header[5] = (unsigned char)(completeimagesize >> 24);

    //reserved
    header[6] = 0;
    header[7] = 0;
    header[8] = 0;
    header[9] = 0;

    //dataoffset (when do we start seeing pixels)
    header[10] = 54;
    header[11] = 0;
    header[12] = 0;
    header[13] = 0;

    //DIB header
    //header size
    header[14] = 40;
    header[15] = 0;
    header[16] = 0;
    header[17] = 0;

    //width
    header[18] = (unsigned char)size_x;
    header[19] = (unsigned char)(size_x >> 8);
    header[20] = (unsigned char)(size_x >> 16);
    header[21] = (unsigned char)(size_x >> 24);

    //height
    header[22] = (unsigned char)size_y;
    header[23] = (unsigned char)(size_y >> 8);
    header[24] = (unsigned char)(size_y >> 16);
    header[25] = (unsigned char)(size_y >> 24);

    //planes
    header[26] = 1;
    header[27] = 0;

    //bitsperpixel
    header[28] = 24;
    header[29] = 0;

    //compression
    header[30] = 0;
    header[31] = 0;
    header[32] = 0;
    header[33] = 0;

    //rawimagesize
    header[34] = (unsigned char)rawimagesize;
    header[35] = (unsigned char)(rawimagesize >> 8);
    header[36] = (unsigned char)(rawimagesize >> 16);
    header[37] = (unsigned char)(rawimagesize >> 24);

    //xpermeter
    header[38] = 35;
    header[39] = 46;
    header[40] = 0;
    header[41] = 0;

    //ypermeter
    header[42] = 35;
    header[43] = 46;
    header[44] = 0;
    header[45] = 0;

    //colorsused
    header[46] = 0;
    header[47] = 0;
    header[48] = 0;
    header[49] = 0;

    //importantcolors
    header[50] = 0;
    header[51] = 0;
    header[52] = 0;
    header[53] = 0;

    FILE *bmp = fopen("mandelbrot.bmp", "wb");
    fwrite(header, 1, 54, bmp);
    fwrite(data, 1, rawimagesize, bmp);
    fclose(bmp);
    free(header);
    return;
}

void plot_pixel(unsigned char r, unsigned char g, unsigned char b, int x, int y, int size_x, int size_y, unsigned char *data) {
    x *= 3;
    data[(y * size_x * 3) + x] = b;
    x++;
    data[(y * size_x * 3) + x] = g;
    x++;
    data[(y * size_x * 3) + x] = r;
    return;
}
