struct complex
{
    int imag;
    float real;
};

struct number
{
    struct complex comp;
    int integers;
} num1, num2;
void main()
{
    num1.integers = 12;
    num1.comp.real = 44.12;
    num2.comp.imag = 11;
    printf("num1.integers  = %d\n", num1.integers);
    printf("num1.comp.real = %0.2f\n", num1.comp.real);
    printf("num1.integers  = %d\n", num2.comp.imag);
}