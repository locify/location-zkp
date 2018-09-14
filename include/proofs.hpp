/* Platin.io 2018
 * written by Vadym Fedyukovych
 * proofs library
 */

#include <iostream>
#ifdef __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
        #include <integer.h>
        #include <modarith.h>
    #elif
        #include "cryptopp/integer.h"
        #include "cryptopp/modarith.h"
    #endif
#elif
    #include "cryptopp/integer.h"
    #include "cryptopp/modarith.h"
#endif

class GInt {
public:
  GInt(CryptoPP::Integer mr, CryptoPP::Integer mi) {r = mr; i = mi;};
  GInt(const long mr, const long mi) {r = mr; i = mi;};
  GInt() {r = 0; i = 0;};

  CryptoPP::Integer r, i;
};

class QInt {
public:
  QInt(CryptoPP::Integer mr, CryptoPP::Integer mi, CryptoPP::Integer mj, CryptoPP::Integer mk) {r = mr; i = mi; j = mj; k = mk;};
  QInt(const long mr, const long mi, const long mj, const long mk) {r = mr; i = mi; j = mj; k = mk;};
  QInt() {r = 0; i = 0; j = 0; k = 0;};

  CryptoPP::Integer r, i, j, k;
};

/* Round to nearest integer
 */
CryptoPP::Integer ground(const CryptoPP::Integer &numr, const CryptoPP::Integer &denomn);

/* GCD() for Gaussian Integers
 */
void ggcd(const GInt &ga, const GInt &gb, GInt &gc);

/* GCRD() for Quaternions
 */
void qgcrd(const QInt &qa, const QInt &qb, QInt &qc);

