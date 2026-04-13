int in_the_set_checker(double a, double b, int count) {
    double re = 0;
    double im = 0;

    for(int i = 0; i < count; i++) {
        double re_old = re;
        re = (re * re) - (im * im) + a;
        im = 2 * re_old * im + b;
        double length = (re * re) + (im * im);
        if(length > 4) {
            return i;
        }
    }

    return 0;
}
