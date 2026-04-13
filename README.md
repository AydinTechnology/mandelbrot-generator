# mandelbrot-generator

This tool can generate a colored Mandelbrot picture (as bitmap). No external libraries needed, all is ANSI C.
Just run the ./build.sh and you're good to go.

Feel free to mess with the hardcoded color palette found in the main.c

Usage: ./mandelbrot iterations_count bitmap_width bitmap_height complex_plane_x_lower complex_plane_x_upper complex_plane_y_lower complex_plane_y_upper
Example: ./mandelbrot 200 2560 1920 -2 1 -1 1 (Will generate a 2560x1920 bitmap using 200 iterations to check for escapes on a domain from -2 to 1 and a range from -1 to 1.)

Shortcomings: this tool uses a color palette of 16 different tints of blue and a simple escape time algorithm to determine which pixel gets which color. This is fun and all but it does cause color banding which is known to hurt the aesthetics a bit.
