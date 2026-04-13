#include <stdio.h>
#include <stdlib.h>
#include "generate_bitmap.h"
#include "mb_funcs.h"

unsigned char palette_r[16] = {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x96, 0xcb, 0x54, 0xad, 0x90, 0xe0, 0xff, 0xff, 0xff, 0xff};
unsigned char palette_g[16] = {0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x4b, 0xcb, 0x54, 0xd8, 0xee, 0xff, 0x47, 0x80, 0xff, 0xff};
unsigned char palette_b[16] = {0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xcb, 0x54, 0xe6, 0x90, 0xff, 0x4c, 0xff, 0x00, 0xff};

int main(int argc, char* argv[]) {
    int iterations_count = atoi(argv[1]);
    int image_width = atoi(argv[2]);
    int image_height = atoi(argv[3]);

    double complex_plane_x_lower = strtod(argv[4], NULL);
    double complex_plane_x_upper = strtod(argv[5], NULL);
    double complex_plane_y_lower = strtod(argv[6], NULL);
    double complex_plane_y_upper = strtod(argv[7], NULL);

    //the "framebuffer"
    unsigned char *raw = malloc(image_width * image_height * 3);

    int bitmap_x = 0;
    int bitmap_y = 0;

    double delta_complex_x = (complex_plane_x_upper-complex_plane_x_lower)/image_width;
    double delta_complex_y = (complex_plane_y_upper-complex_plane_y_lower)/image_height;


    //this is where it happens
    for(double current_complex_y = complex_plane_y_lower; current_complex_y < complex_plane_y_upper; current_complex_y += delta_complex_y) {
        for(double current_complex_x = complex_plane_x_lower; current_complex_x < complex_plane_x_upper; current_complex_x += delta_complex_x) {

            int result = in_the_set_checker(current_complex_x, current_complex_y, iterations_count);
            if(result == 0) {
                plot_pixel(0, 0, 0, bitmap_x, bitmap_y, image_width, image_height, raw);
            } else {
                plot_pixel(palette_r[result % 16], palette_g[result % 16], palette_b[result % 16], bitmap_x, bitmap_y, image_width, image_height, raw);
            }
            bitmap_x++;
        }
        bitmap_y++;
        bitmap_x = 0;
    }

    produce_bitmap(image_width, image_height, raw);
    free(raw);
    return 0;
}
