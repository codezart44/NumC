//config.h

#ifndef _CONFIG_H_
#define _CONFIG_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Mathematical constants and expressions

#define E  2.718281828459045        // Euler's number `e` with 15 point decimal precision. Further decimals: ...2353602874713526624977572470936999595749669676277...
#define PI 3.141592653589793        // Pi `π` with 15 point decimal precision. Further decimals: ...2384626433832795028841971693993751058209749445923...

#define SQR_E  7.389056098930650    // Square e `e^2` with 15 point decimal precision. Further decimals: ...2272304274605750078131803155705518473240871278225...
#define SQR_PI 9.869604401089358    // Square pi `π^2` with 15 point decimal precision. Further decimals: ...6188344909998761511353136994072407906264133493762...

#define SQRT_E  2.718281828459045       // Square root of Euler's number `√e` with 15 point decimal precision. Further decimals: ...2353602874713526624977572470936999595749669676277...
#define SQRT_PI 3.141592653589793       // Square root of pi `√π` with 15 point decimal precision. Further decimals: ...2384626433832795028841971693993751058209749445923...
#define SQRT_2  1.414213562373095       // Square root of 2 `√2` with 15 point decimal precision. Further decimals: ...0488016887242096980785696718753769480731766797379...


#define TAYLOR_APPROX_MAX_ITER 20       // maximum number of terms calculated
#define TAYLOR_APPROX_TOLERANCE 1e-12   // break iteration when term_i becomes smaller than tolerance




#define MAXIMUM_LENGTH 1000
#define MAXIMUM_DIMENSION 5
#define SENTINEL_VALUE -999

typedef unsigned int Uint;
typedef unsigned short Ushort;
typedef unsigned long Ulong;


#endif  // _CONFIG_H_