#include <inttypes.h>

uint64_t descendingOrder(uint64_t n) {
    uint8_t nums[20] = {0};
    int offset = 0;
    uint64_t res = 0;

    while (n > 0) {
        nums[offset] = n % 10;
        n /= 10;
        offset++;
    }

    while (offset > 0) {
        uint8_t maxDigit = 0;
        int maxIndex = 0;
        for (int i = 0; i < offset; i++) {
            if (nums[i] > maxDigit) {
                maxDigit = nums[i];
                maxIndex = i;
            }
        }
      
        res = res * 10 + maxDigit;

        for (int i = maxIndex; i < offset - 1; i++) {
            nums[i] = nums[i + 1];
        }
        offset--;
    }

    return res;
}
