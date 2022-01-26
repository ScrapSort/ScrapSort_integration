#ifndef SCRAPSORT_INTEGRATION_UTILS_H
#define SCRAPSORT_INTEGRATION_UTILS_H

/* Debugging */

#define DEBUG true

#if DEBUG == true
#define D(x) x
#else
#define D(x)
#endif

/*
 * Usage:
 *    D(std::cout << "debug example" << std::endl);
 *
 *    D(
 *        std::cout << "multiline..." << std::endl;
 *        int do_some_debug_calculation = 3;
 *        std::cout << "...debug example" << std::endl;
 *    )
 */

#endif // SCRAPSORT_INTEGRATION_UTILS_H
