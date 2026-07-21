/* Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet); */

unsigned char swap_bits(unsigned char octet)
{
    unsigned char left = octet << 4;
    unsigned char right = octet >> 4;

    unsigned char result = left | right;

    return result;
}