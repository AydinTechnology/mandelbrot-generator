int in_the_set_checker(double a, double b, int count) {
    double re = 0;
    double im = 0;

    //the idea is that (a+bi)^2 = a^2 - b^2 + 2abi
    //therefore, we can omit complex numbers entirely and just split them up in two seperate variable sorts: re... and im...
    for(int i = 0; i < count; i++) {
        double re_old = re;
        double re_squared = (re * re);  //can be reused for z = (a+bi)^2 and |z|
        double im_squared = (im * im);

        re = re_squared - im_squared + a;
        im = 2 * re_old * im + b;

        double length = re_squared + im_squared;    //instead of using the pythagorean theorem which involves taking the square root (expensive on today's hardware) and compare to 2,
        if(length > 4) {                            //we can just compare Re(z)^2 + Im(z)^2 against 4
            return i;
        }
    }

    return 0;
}
