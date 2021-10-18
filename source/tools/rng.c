/**
 * This random number generator is based on https://arxiv.org/abs/2004.06278v2
 */

static inline int squares(int ctr, int key) {
    int x, y, z;
    y = x = ctr * key;
    z = y + key;
    x = x * x + y;
    x = (x >> 16) | (x << 16); /* round 1 */
    x = x * x + z;
    x = (x >> 16) | (x << 16); /* round 2 */
    return (x * x + y) >> 16;  /* round 3 */
}

int random(void) {
    static int ctr = 1;
    static int key = 0xa7a7;

    ctr = squares(ctr, key);
    return ctr;
}
