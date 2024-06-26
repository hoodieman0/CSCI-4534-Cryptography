#include "UnitTest-DSA.hpp"

/// ----------------------------------------------------------------------------
/// @brief see if input 1 on homework works for DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputA(){
    try {
        int p = 7,
            q = 3,
            h = 3,
            x = 2,
            k = 1,
            HM1 = 3,
            HM2 = 4;

            DSA cipher(p, q, h, x, true, true);
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Sign Hash:" << endl;
            const Signature sign = cipher.signHash(HM1, k);

            if (sign.s != 1 || sign.r != 2) throw "Returned signature is wrong!";
            
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Verify Real Hash" << endl;
            bool goodVerification = cipher.verifyHash(HM1, sign);

            if (!goodVerification) throw "Good verification went wrong!";

            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Verify Fake Hash" << endl;
            bool badVerification = cipher.verifyHash(HM2, sign);

            if (badVerification) throw "Bad verification went wrong!";
            cout << "----------------------------------------------------------------------------" << endl;
    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }
    
    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief see if input 2 on homework works for DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputB(){
    try {
        int p = 47,
            q = 23,
            h = 5,
            x = 7,
            k = 13,
            HM1 = 5,
            HM2 = 4;

            DSA cipher(p, q, h, x, true, true);
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Sign Hash:" << endl;
            const Signature sign = cipher.signHash(HM1, k);

            if (sign.s != 9 || sign.r != 16) throw "Returned signature is wrong!";
            
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Verify Real Hash" << endl;
            bool goodVerification = cipher.verifyHash(HM1, sign);

            if (!goodVerification) throw "Good verification went wrong!";

            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Verify Fake Hash" << endl;
            bool badVerification = cipher.verifyHash(HM2, sign);

            if (badVerification) throw "Bad verification went wrong!";
            cout << "----------------------------------------------------------------------------" << endl;
    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief see if custom inputs work for DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputC(){
    try {
        int p = 151,
            q = 50,
            h = 64,
            x = 29,
            k = 41,
            HM1 = 11,
            HM2 = 33;

            DSA cipher(p, q, h, x, true, true);
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Sign Hash:" << endl;
            const Signature sign = cipher.signHash(HM1, k);

            if (sign.s != 23 || sign.r != 8) throw "Returned signature is wrong!";
            
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Verify Real Hash" << endl;
            bool goodVerification = cipher.verifyHash(HM1, sign);

            if (!goodVerification) throw "Good verification went wrong!";

            cout << "----------------------------------------------------------------------------" << endl;
            cout << "Verify Fake Hash" << endl;
            bool badVerification = cipher.verifyHash(HM2, sign);

            if (badVerification) throw "Bad verification went wrong!";
            cout << "----------------------------------------------------------------------------" << endl;
    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll(){
    int passed = 0, failed = 0;

    cout << "Running all unit tests for DSA class" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    cout << "Running Unit Test - Input A..." << endl;
    if (UnitTest_InputA()) { cout << "Unit Test - Input A -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Input A -> Passed Test \u2713" << endl; passed++; }

    cout << "Running Unit Test - Input B..." << endl;
    if (UnitTest_InputB()) { cout << "Unit Test - Input B -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Input B -> Passed Test \u2713" << endl; passed++; }

    cout << "Running Unit Test - Input C..." << endl;
    if (UnitTest_InputC()) { cout << "Unit Test - Input C -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Input C -> Passed Test \u2713" << endl; passed++; }


    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}