
class Mandelbrot {
public:
    const static int NUMBER_OF_ITERATIONS = 1000;
    Mandelbrot();
    virtual ~Mandelbrot();
    static int getIterations(const double &x, const double &y);
};
