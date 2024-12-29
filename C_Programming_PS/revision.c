#include <stdint.h>
#include <stdio.h>

#define GPIO_ODR ((volatile uint32_t *)0x10000000)
#define GPIO_ODR_d *((volatile uint32_t *)0x10000000)

// using structure
struct GPIO_ODR_t
{
    uint32_t pin0 : 1;
    uint32_t pin2 : 1;
    uint32_t pin3 : 1;
    uint32_t pin4 : 1;
    uint32_t reversed : 28;
};

union UGPIO_ODR_t
{
    struct GPIO_ODR_t GPIO_ODR_reg;
    uint32_t ODR;
};

int main()
{
    // Different Methods to wriute a value on register.
    //*((volatile uint32_t *)0x1000000) |= 1UL << 16;
    //*GPIO_ODR |= 1UL << 16;
    // GPIO_ODR_d |= 1 << 16;
    // using struct and union

    // volatile union UGPIO_ODR_t *ODR_Reg = (union UGPIO_ODR_t *)0x100000000;

    // Reading Big-Indian And Little Indian.
    int memory[] = {0x12, 0x34, 0x56, 0x76};
    int value;
    // Reading the memory as a big-indian
    value = memory[0] << 24 | memory[1] << 16 | memory[2] << 8 | memory[3];

    printf("Big-Indian Value: %d\n", value);
    value = memory[3] << 24 | memory[2] << 16 | memory[1] << 8 | memory[0];
    printf("Little-Indian Value: %d\n", value);

    return 0;
}