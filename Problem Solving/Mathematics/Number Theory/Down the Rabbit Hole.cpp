#include<stdio.h>
#define ll long long
#define p 1000000007

ll x, y;

// euclidean gcd
void egcd(ll a, ll b) {
    if (!b) {
        x = 1;
        y = 0;
    } else {
        egcd(b, a % b);
        ll t = x - (a / b) * y;
        x = y;
        y = t;
    }
}

// modular inverse
ll inv(ll a) {
    egcd(a, p);
    return x % p;
}

// complex number x + y*i
struct COMPLEX {
    ll x, y;
    COMPLEX(ll x = 0, ll y = 0) : x(x), y(y) {}

    // the reciprocal
    COMPLEX recip() {
        ll r = inv((x * x + y * y) % p);
        return COMPLEX(x * r % p, -y * r % p);
    }

    // add to b
    COMPLEX operator+(COMPLEX b) {
        return COMPLEX((x + b.x) % p, (y + b.y) % p);
    }

    // multiply with b
    COMPLEX operator*(COMPLEX b) {
        return COMPLEX((x * b.x - y * b.y) % p, (x * b.y + y * b.x) % p);
    }

    // divide with b
    COMPLEX operator/(COMPLEX b) {
        b = b.recip();
        return COMPLEX((x * b.x - y * b.y) % p, (x * b.y + y * b.x) % p);
    }

    // complex conjugate
    COMPLEX conj() {
        return COMPLEX(x, -y);
    }

    // is this a nonzero complex number?
    int nonzero() {
        return x || y;
    }
};

COMPLEX ra, rb, rc, rd;

// compose two mobius transformations:
// f(z) = (fa*z + fb)/(fc*z + fd)
// g(z) = (ga*z + gb)/(gc*z + gd)
void omul(COMPLEX fa, COMPLEX fb, COMPLEX fc, COMPLEX fd,
          COMPLEX ga, COMPLEX gb, COMPLEX gc, COMPLEX gd) {
    ra.x = (fa.x * ga.x - fa.y * ga.y + fb.x * gc.x - fb.y * gc.y) % p;
    ra.y = (fa.x * ga.y + fa.y * ga.x + fb.x * gc.y + fb.y * gc.x) % p;
    rb.x = (fa.x * gb.x - fa.y * gb.y + fb.x * gd.x - fb.y * gd.y) % p;
    rb.y = (fa.x * gb.y + fa.y * gb.x + fb.x * gd.y + fb.y * gd.x) % p;
    rc.x = (fc.x * ga.x - fc.y * ga.y + fd.x * gc.x - fd.y * gc.y) % p;
    rc.y = (fc.x * ga.y + fc.y * ga.x + fd.x * gc.y + fd.y * gc.x) % p;
    rd.x = (fc.x * gb.x - fc.y * gb.y + fd.x * gd.x - fd.y * gd.y) % p;
    rd.y = (fc.x * gb.y + fc.y * gb.x + fd.x * gd.y + fd.y * gd.x) % p;
}

// iterate the mobius transformation e times (using fast exponentiation):
// f(z) = (a*z + b)/(c*z + d)
void opow(COMPLEX a, COMPLEX b, COMPLEX c, COMPLEX d, ll e) {
    if (e == 1) {
        ra = a;
        rb = b;
        rc = c;
        rd = d;
    } else if (e & 1) {
        opow(a, b, c, d, e - 1);
        omul(ra, rb, rc, rd, a, b, c, d);
    } else {
        omul(a, b, c, d, a, b, c, d);
        opow(ra, rb, rc, rd, e >> 1);
    }
}

// fraction n/d
struct FRACTION {
    ll n, d;
};

// the fraction f modulo p = 10^9+7
#define fix(f) (f.n * inv(f.d) % p)

// zero and one
COMPLEX ZERO = COMPLEX();
COMPLEX ONE = COMPLEX(1);

char s[11];
int main() {

    // take number of cases
    int z;
    scanf("%d", &z);

    for (int cas = 1; cas <= z; cas++) {
        int n;
        ll k;
        FRACTION tx, ty, ta, tb, tc;
        COMPLEX c;

        // take n, k and (x, y)
        scanf("%d %lld %lld/%lld %lld/%lld", &n, &k, &tx.n, &tx.d, &ty.n, &ty.d);

        // initial mobius transformation
        COMPLEX fa = ONE;
        COMPLEX fb = ZERO;
        COMPLEX fc = ZERO;
        COMPLEX fd = ONE;
        int has_conj = 0; // whether the transformation takes the conjugate first

        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            if (*s == 'S') {
                // scaling S_c, which is just
                // S_c(z) = c*z = (c*z + 0)/(0*z + 1)
                scanf("%lld/%lld", &tc.n, &tc.d);
                c = COMPLEX(fix(tc));
                fa = fa * c;
                fb = fb * c;
            } else if (*s == 'T') {
                // translation T_{a,b}, which is just
                // T_{a,b}(z) = z + (a+b*i) = (1*z + (a+b*i))/(0*z + 1)
                scanf("%lld/%lld %lld/%lld", &ta.n, &ta.d, &tb.n, &tb.d);
                COMPLEX c = COMPLEX(fix(ta), fix(tb));
                fa = fa + fc * c;
                fb = fb + fd * c;
            } else if (*s == 'R') {
                // rotation R_{a,b}, which is just
                // R_{a,b}(z) = z * (a-b*i) = ((a-b*i)*z + 0)/(0*z + 1)
                scanf("%lld/%lld %lld/%lld", &ta.n, &ta.d, &tb.n, &tb.d);
                tb.n = -tb.n;
                COMPLEX c = COMPLEX(fix(ta), fix(tb));
                fa = fa * c;
                fb = fb * c;
            } else if (*s == 'F') {
                scanf("%s", s);
                if (*s == 'Y') {
                    // flip-y F_Y, which is just
                    // F_Y(z) = -conj(z) = (-1*conj(z) + 0)/(0*conj(z) + 1)
                    fa.x = -fa.x;
                    fb.x = -fb.x;
                    fc.y = -fc.y;
                    fd.y = -fd.y;
                    has_conj = !has_conj;
                } else {
                    // flip-x F_X, which is just
                    // F_X(z) = conj(z) = (1*conj(z) + 0)/(0*conj(z) + 1)
                    fa.y = -fa.y;
                    fb.y = -fb.y;
                    fc.y = -fc.y;
                    fd.y = -fd.y;
                    has_conj = !has_conj;
                }
            } else {
                // circle inversion I, which is just
                // I(z) = 1/conj(z) = (0*conj(z) + 1)/(1*conj(z) + 0)
                COMPLEX ft;
                ft = fc; fc = fa; fa = ft;
                ft = fd; fd = fb; fb = ft;
                fa.y = -fa.y;
                fb.y = -fb.y;
                fc.y = -fc.y;
                fd.y = -fd.y;
                has_conj = !has_conj;
            }
        }

        COMPLEX z = COMPLEX(fix(tx), fix(ty));
        int inf = 0; // whether we're at point at infinity

        // now we need to calculate f^k (z)

        if (has_conj) { // has conjugate. we'd like to remove it by squaring f

            if (k & 1) { // k is odd. take z <- f(z) first
                z.y = -z.y;
                COMPLEX D = fc * z + fd;
                if (D.nonzero()) {
                    COMPLEX N = fa * z + fb;
                    z = N / D;
                } else {
                    inf = 1;
                }
            }

            // square f and halve k
            k >>= 1;
            omul(fa, fb, fc, fd, fa.conj(), fb.conj(), fc.conj(), fd.conj());
            fa = ra;
            fb = rb;
            fc = rc;
            fd = rd;
        }


        if (k) {
            // calculate f^k
            opow(fa, fb, fc, fd, k);

            // calculate f^k (z)
            if (inf) {
                if (rc.nonzero()) {
                    z = ra / rc;
                    inf = 0;
                }
            } else {
                COMPLEX D = rc * z + rd;
                if (D.nonzero()) {
                    COMPLEX N = ra * z + rb;
                    z = N / D;
                } else {
                    inf = 1;
                }
            }
        }

        // print answer
        if (inf) {
            printf("WONDERLAND\n");
        } else {
            ll x = z.x % p;
            ll y = z.y % p;
            if (x < 0) x += p;
            if (y < 0) y += p;
            printf("%lld %lld\n", x, y);
        }
    }
}
