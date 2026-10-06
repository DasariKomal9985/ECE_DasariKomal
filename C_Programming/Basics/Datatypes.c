#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

struct Sensor
{
    uint16_t adc_value;
    float temperature;
};

union Data
{
    uint32_t integer;
    float decimal;
};

enum State
{
    OFF,
    ON
};

typedef uint32_t counter_t;

int main(void)
{
    char ch = 'A';
    signed char sc = -100;
    unsigned char uc = 200;

    short int si = -30000;
    unsigned short int usi = 60000;

    int i = -100000;
    unsigned int ui = 100000;

    long int li = 1000000L;
    unsigned long int uli = 2000000UL;

    long long int lli = 9000000000LL;
    unsigned long long int ulli = 18000000000ULL;

    float f = 3.14f;
    double d = 123.456;
    long double ld = 123.456L;

    bool flag = true;

    int8_t i8 = -100;
    uint8_t u8 = 200;

    int16_t i16 = -30000;
    uint16_t u16 = 60000;

    int32_t i32 = -100000;
    uint32_t u32 = 100000;

    int64_t i64 = -9000000000LL;
    uint64_t u64 = 18000000000ULL;

    size_t size = sizeof(int);

    int array[3] = {10, 20, 30};
    int *ptr = &i;

    struct Sensor sensor = {4095, 27.5f};

    union Data data;
    data.integer = 100;

    enum State state = ON;

    counter_t counter = 5000;

    printf("char              = %c\n", ch);
    printf("signed char       = %hhd\n", sc);
    printf("unsigned char     = %hhu\n", uc);

    printf("short int         = %hd\n", si);
    printf("unsigned short    = %hu\n", usi);

    printf("int               = %d\n", i);
    printf("unsigned int      = %u\n", ui);

    printf("long int          = %ld\n", li);
    printf("unsigned long     = %lu\n", uli);

    printf("long long         = %lld\n", lli);
    printf("unsigned long long= %llu\n", ulli);

    printf("float             = %f\n", f);
    printf("double            = %f\n", d);
    printf("long double       = %Lf\n", ld);

    printf("bool              = %d\n", flag);

    printf("int8_t            = %" PRId8 "\n", i8);
    printf("uint8_t           = %" PRIu8 "\n", u8);

    printf("int16_t           = %" PRId16 "\n", i16);
    printf("uint16_t          = %" PRIu16 "\n", u16);

    printf("int32_t           = %" PRId32 "\n", i32);
    printf("uint32_t          = %" PRIu32 "\n", u32);

    printf("int64_t           = %" PRId64 "\n", i64);
    printf("uint64_t          = %" PRIu64 "\n", u64);

    printf("size_t            = %zu\n", size);

    printf("array[0]           = %d\n", array[0]);
    printf("pointer value      = %d\n", *ptr);

    printf("ADC value          = %u\n", sensor.adc_value);
    printf("Temperature        = %.2f\n", sensor.temperature);

    printf("Union integer      = %u\n", data.integer);
    printf("Enum state         = %d\n", state);

    printf("typedef counter    = %" PRIu32 "\n", counter);

    return 0;
}
