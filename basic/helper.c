#include "helper.h"

void ftoa(char *buffer, float f)
{
	int wholePart = f;

	// Deposit the whole part of the number.
    if (wholePart == 0 && f < 0)
    {
        *buffer++ = '-';
    }
	itoa(wholePart, buffer, 10);

	// Now work on the faction if we need one.

    // We do, so locate the end of the string and insert
    // a decimal point.
    int precision = 5;
    char *endOfString = buffer + strlen(buffer);
    *endOfString++ = '.';

    // Now work on the fraction, be sure to turn any negative
    // values positive.

    if (f < 0) {
        f *= -1;
        wholePart *= -1;
    }

    float fraction = f - wholePart;
    while (precision > 0)
    {
        // Multiple by ten and pull out the digit.
        fraction *= 10;
        wholePart = fraction;
        *endOfString++ = '0' + wholePart;

        // Update the fraction and move on to the
        // next digit.
        fraction -= wholePart;
        precision--;
    }

    // Terminate the string.

    *endOfString = '\0';
}
