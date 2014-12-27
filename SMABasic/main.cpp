//
//  main.cpp
//  SMABasic
//
//  Created by Brock Whittaker on 12/26/14.
//  Copyright (c) 2014 Brock Whittaker. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void generator (int ndays) {
    for (int y = 0; y < ndays; y++) {
        cout << "stock_prices[x - " << y << "] + ";
    }
}

int main() {
    cout << "Welcome to the simple moving average trading algorithm. Please enter your password now." << endl;
    string password;
    cin >> password;
    if (password == "B.j.W.2013") {
        cout << endl << "Thank you very much. Now please enter which SMA you would like to use. You can select from 5, 15, or 30." << endl;
        int sma_number;
        cin >> sma_number;
        cout << endl << "Would you like to trial test the asset crossing above the SMA or below the SMA? Enter 'above' or 'below'." << endl;
        string above_below;
        cin >> above_below;
        cout << endl << "How many days would you like to hold thes asset after purchasing it?" << endl;
        int daysinterval;
        cin >> daysinterval;
        
        double stock_prices [252] = {2088.77, 2081.88, 2082.17, 2078.54, 2070.65, 2061.23, 2012.89, 1972.74, 1989.63, 2002.33, 2035.33, 2026.14, 2059.82, 2060.31, 2075.37, 2071.92, 2074.33, 2066.55, 2053.44, 2067.56, 2072.83, 2067.03, 2069.41, 2063.5, 2052.75, 2048.72, 2051.8, 2041.32, 2039.82, 2039.33, 2038.25, 2039.68, 2038.26, 2031.92, 2031.21, 2023.57, 2012.1, 2017.81, 2018.05, 1994.65, 1982.3, 1985.05, 1961.63, 1964.58, 1950.82, 1927.11, 1941.28, 1904.01, 1886.76, 1862.76, 1862.49, 1877.7, 1874.74, 1906.13, 1928.21, 1968.89, 1935.1, 1964.82, 1967.9, 1946.17, 1946.16, 1972.29, 1977.8, 1982.85, 1965.99, 1998.3, 1982.77, 1994.29, 2010.4, 2011.36, 2001.57, 1998.98, 1984.13, 1985.54, 1997.45, 1995.69, 1988.44, 2001.54, 2007.71, 1997.65, 2000.72, 2002.28, 2003.37, 1996.74, 2000.12, 2000.02, 1997.92, 1988.4, 1992.37, 1986.51, 1981.6, 1971.74, 1955.06, 1955.18, 1946.72, 1933.75, 1936.92, 1931.59, 1909.57, 1920.24, 1920.21, 1938.99, 1925.15, 1930.67, 1970.07, 1969.95, 1978.91, 1978.34, 1987.98, 1987.01, 1983.53, 1973.63, 1978.22, 1958.12, 1981.57, 1973.28, 1977.1, 1967.57, 1964.68, 1972.83, 1963.71, 1977.65, 1985.44, 1974.62, 1973.32, 1960.23, 1960.96, 1957.22, 1959.53, 1949.98, 1962.61, 1962.87, 1959.48, 1956.98, 1941.99, 1937.78, 1936.16, 1930.11, 1943.89, 1950.79, 1951.27, 1949.44, 1940.46, 1927.88, 1924.24, 1924.97, 1923.57, 1920.03, 1909.78, 1911.91, 1900.53, 1892.49, 1888.03, 1872.83, 1885.08, 1877.86, 1870.85, 1888.53, 1897.45, 1896.65, 1878.48, 1875.63, 1878.21, 1867.72, 1884.66, 1881.14, 1883.68, 1883.95, 1878.33, 1869.43, 1863.4, 1878.61, 1875.39, 1879.55, 1871.89, 1864.85, 1862.31, 1842.98, 1830.61, 1815.69, 1833.08, 1872.18, 1851.96, 1845.04, 1865.09, 1888.77, 1890.9, 1885.52, 1872.34, 1857.62, 1849.04, 1852.56, 1865.62, 1857.44, 1866.52, 1872.01, 1860.77, 1872.25, 1858.83, 1841.13, 1846.34, 1868.2, 1867.63, 1877.17, 1878.04, 1877.03, 1873.81, 1873.91, 1845.73, 1859.45, 1854.29, 1845.16, 1845.12, 1847.61, 1836.25, 1839.78, 1828.75, 1840.76, 1838.63, 1829.83, 1819.26, 1819.75, 1799.84, 1797.02, 1773.43, 1751.64, 1755.2, 1741.89, 1782.59, 1794.19, 1774.2, 1792.5, 1781.56, 1790.29, 1828.46, 1844.86, 1843.8, 1838.7, 1845.89, 1848.38, 1838.88, 1819.2, 1842.37, 1838.13, 1837.49, 1837.88, 1826.77, 1831.37, 1831.98, 1848.36, 1841.07, 1841.4};
        
        int arraynum = sizeof(stock_prices) / 8;
        
        double SMA_Array [252] = {};
        for (int x = 9; x < arraynum; x++) {
            double SMA = (stock_prices[x - 0] + stock_prices[x - 1] + stock_prices[x - 2] + stock_prices[x - 3] + stock_prices[x - 4]) / 5;
            SMA_Array[x] = SMA;
        }
        
            if (sma_number == 5) {
                for (int x = 9; x < arraynum; x++) {
                    double SMA = (stock_prices[x - 0] + stock_prices[x - 1] + stock_prices[x - 2] + stock_prices[x - 3] + stock_prices[x - 4]) / 5;
                    SMA_Array[x] = SMA;
                }
            }
            if (sma_number == 15){
                for (int x = 9; x < arraynum; x++) {
                    double SMA = (stock_prices[x - 0] + stock_prices[x - 1] + stock_prices[x - 2] + stock_prices[x - 3] + stock_prices[x - 4] + stock_prices[x - 5] + stock_prices[x - 6] + stock_prices[x - 7] + stock_prices[x - 8] + stock_prices[x - 9] + stock_prices[x - 10] + stock_prices[x - 11] + stock_prices[x - 12] + stock_prices[x - 13] + stock_prices[x - 14]) / 15;
                    SMA_Array[x] = SMA;
                }
            }
            if (sma_number == 30){
                for (int x = 9; x < arraynum; x++) {
                    double SMA = (stock_prices[x - 0] + stock_prices[x - 1] + stock_prices[x - 2] + stock_prices[x - 3] + stock_prices[x - 4] + stock_prices[x - 5] + stock_prices[x - 6] + stock_prices[x - 7] + stock_prices[x - 8] + stock_prices[x - 9] + stock_prices[x - 10] + stock_prices[x - 11] + stock_prices[x - 12] + stock_prices[x - 13] + stock_prices[x - 14] + stock_prices[x - 15] + stock_prices[x - 16] + stock_prices[x - 17] + stock_prices[x - 18] + stock_prices[x - 19] + stock_prices[x - 20] + stock_prices[x - 21] + stock_prices[x - 22] + stock_prices[x - 23] + stock_prices[x - 24] + stock_prices[x - 25] + stock_prices[x - 26] + stock_prices[x - 27] + stock_prices[x - 28] + stock_prices[x - 29]) / 30;
                    SMA_Array[x] = SMA;
                }
            }

        double daily [252];
        for (int x = 0; x < arraynum; x++) {
            daily[x] = stock_prices[x] / stock_prices[x + 1];
        }
        
        string YES_NO [252] = {};
        if (above_below == "above") {
            for (int z = 0; z < arraynum; z++) {
                if (stock_prices[z] > SMA_Array[z]) {
                    if (stock_prices[z-1] < SMA_Array[z-1]) {
                        YES_NO[z] = "YES";
                    } else {
                        YES_NO[z] = "NO";
                    }
                } else {
                    YES_NO[z] = "NO";
                }
            }
        } else {
            for (int z = 0; z < arraynum; z++) {
                if (stock_prices[z] < SMA_Array[z]) {
                    if (stock_prices[z-1] > SMA_Array[z-1]) {
                        YES_NO[z] = "YES";
                    } else {
                        YES_NO[z] = "NO";
                    }
                } else {
                    YES_NO[z] = "NO";
                }
            }
        }
        
        double day_changes [250] = {}; // if this outputs a weird bug, it is because this array is too small!
        int y = 0;
        for (int x = 0; x < arraynum; x++) {
            if (YES_NO[x] == "YES") {
                y = y + 1;
                day_changes[y] = stock_prices[x] / stock_prices[x + daysinterval];
            }
        }
        
        for (int x = 0; x < arraynum; x++) {
            if (day_changes[x] < 0.5) {
                day_changes[x] = 1; // to rid of zeros that when multiplied would null the equation.
            }
            if (day_changes[x] > 2) {
                day_changes[x] = 1;
            }
        }
        
        double product = day_changes[0];
        for (int x = 0; x < arraynum; x++) {
            if (x > 0) {
                product *= day_changes[x];
            }
        }
        
        product = (product - 1) * 100;
        cout << endl << "The amount of money you would have made over the last " << arraynum << " trading days using this strategy is " << product << "%" << "." << endl << endl;
       
        cout << "Here are the particular trade returns over the interval using the above algorithm:" << endl << endl;
        int counter = 0;
        cout << "\t";
        for (int x = 0; x < arraynum; x++) {
            if (day_changes[x] != 1) {
                cout << day_changes[x] << ", ";
                counter = counter + 1;
                if (counter % 5 == 0) {
                    cout << endl << "\t";
                }
            }
        }
        cout << endl << endl;
    }
}
