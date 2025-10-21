// this is the ONLY file you should submit to Gradescope
#include "nth_root.h"
#include "test_helpers.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // TODO(student): just call the function with various values of n and x
        nth_root(2, 1);
        nth_root(0, 1); // A
        nth_root(4, -1); // B
        nth_root(-1, 0); // C
        nth_root(1, 1); // D
        nth_root(-1, 1); // E
        nth_root(-2, 1); // F
        nth_root(-6, 1); // G
        nth_root(6, 1); // I
        nth_root(1, 0); // K
        nth_root(3, -2); // M
        nth_root(2, 5); // N
        nth_root(2, 1); // O
        nth_root(2, 2.4); // P



    }

    {   // TRY HARD
        // TODO(student): report the value
        report(nth_root(2, 1));
        report(nth_root(-2, 1));
        report(nth_root(0,1));
        report(nth_root(4,-1));
        report(nth_root(-1, 0));
        report(nth_root(1, 1));
    }

    {   // TRY HARDER
        // TODO(student): compare the actual value to the expected value
        expect_near(nth_root(2, 1), 1);

        expect_throw(nth_root(0, 1), std::domain_error); // if n = 0
        expect_throw(nth_root(4, -1), std::domain_error); // if n even, x < 0
        expect_throw(nth_root(-1, 0), std::domain_error); // if n < 0, x = 0
    }
}
