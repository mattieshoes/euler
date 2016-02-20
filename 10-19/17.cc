// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 
// 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many 
// letters would be used?
//
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 
// 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing 
// out numbers is in compliance with British usage.


#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<int> letters(1001, 0);
    letters[1]  += sizeof("one") - 1;
    letters[2]  += sizeof("two") - 1;
    letters[3]  += sizeof("three") - 1;
    letters[4]  += sizeof("four") - 1;
    letters[5]  += sizeof("five") - 1;
    letters[6]  += sizeof("six") - 1;
    letters[7]  += sizeof("seven") - 1;
    letters[8]  += sizeof("eight") - 1;
    letters[9]  += sizeof("nine") - 1;
    letters[10] += sizeof("ten") - 1;
    letters[11] += sizeof("eleven") - 1;
    letters[12] += sizeof("twelve") - 1;
    letters[13] += sizeof("thirteen") - 1;
    letters[14] += sizeof("fourteen") - 1;
    letters[15] += sizeof("fifteen") - 1;
    letters[16] += sizeof("sixteen") - 1;
    letters[17] += sizeof("seventeen") - 1;
    letters[18] += sizeof("eighteen") - 1;
    letters[19] += sizeof("nineteen") - 1;
    letters[20] += sizeof("twenty") - 1;
    letters[30] += sizeof("thirty") - 1;
    letters[40] += sizeof("forty") - 1;
    letters[50] += sizeof("fifty") - 1;
    letters[60] += sizeof("sixty") - 1;
    letters[70] += sizeof("seventy") - 1;
    letters[80] += sizeof("eighty") - 1;
    letters[90] += sizeof("ninety") - 1;
    letters[100] += sizeof("onehundred") - 1;
    letters[200] += sizeof("twohundred") - 1;
    letters[300] += sizeof("threehundred") - 1;
    letters[400] += sizeof("fourhundred") - 1;
    letters[500] += sizeof("fivehundred") - 1;
    letters[600] += sizeof("sixhundred") - 1;
    letters[700] += sizeof("sevenhundred") - 1;
    letters[800] += sizeof("eighthundred") - 1;
    letters[900] += sizeof("ninehundred") - 1;
    letters[1000] += sizeof("onethousand") - 1;
    for (int ii = 20; ii < 100; ii += 10)
        for (int jj = 1; jj < 10; jj++)
            letters[ii+jj] += letters[ii] + letters[jj];
    for (int ii = 100; ii < 1000; ii += 100)
        for (int jj = 1; jj < 100; jj++)
            letters[ii + jj] = letters[ii] + sizeof("and") -1 + letters[jj];

    unsigned int sum = 0;
    for(int ii = 1; ii <= 1000; ii++)
        sum += letters[ii];
    cout << "Sum: " << sum << endl;   
 
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
