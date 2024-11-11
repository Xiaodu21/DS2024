//
// Created by lenovo on 2024/11/10.
//

#ifndef DS2024A_BITMAP_H
#define DS2024A_BITMAP_H

#endif //DS2024A_BITMAP_H
#ifndef BITMAP_H
#define BITMAP_H

#include <cstring>

class Bitmap {
private:
    unsigned char* M;
    int N, _sz;
    void init(int n) {
        M = new unsigned char[N = (n + 7) / 8];
        memset(M, 0, N);
        _sz = 0;
    }

public:
    Bitmap(int n = 8) { init(n); }
    ~Bitmap() { delete[] M; M = nullptr; _sz = 0; }

    void set(int k) { expand(k); _sz++; M[k >> 3] |= (0x80 >> (k & 0x07)); }
    void clear(int k) { expand(k); _sz--; M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
    bool test(int k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }

    void expand(int k) {
        if (k < 8 * N) return;
        int oldN = N;
        unsigned char* oldM = M;
        init(2 * k);
        memcpy(M, oldM, oldN);
        delete[] oldM;
    }
};
#endif // BITMAP_H
