/*
 Copyright (C) 2016 by Wojciech Jaśkowski, Michał Kempka, Grzegorz Runc, Jakub Toczek, Marek Wydmuch

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

#include "ViZDoomUtilities.h"
#include <thread>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


namespace vizdoom {

    double DoomTicsToMs(double tics, int ticrate) {
        return static_cast<double>(1000) / ticrate * tics;
    }

    double MsToDoomTics(double ms, int ticrate) {
        return static_cast<double>(ticrate) / 1000 * ms;
    }

    double DoomFixedToDouble(int doomFixed) {
        double res = static_cast<double>(doomFixed) / 65536.0;
        return res;
    }

    bool isBinaryButton(Button button){
        return button < BinaryButtonCount;
    }

    bool isDeltaButton(Button button){
        // return button >= BinaryButtonCount && button < (BinaryButtonCount + DeltaButtonCount);
        return button >= BinaryButtonCount && button < ButtonCount;
    }

    std::string timestamp()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        std::thread::id this_id = std::this_thread::get_id();

        std::ostringstream ss;
        ss << "[Thread " << this_id << "] ";
        ss << "[";
        ss << 1900 + ltm->tm_year;
        ss << "-";
        ss << 1 + ltm->tm_mon;
        ss << "-";
        ss << ltm->tm_mday;
        ss << " ";
        if (ltm->tm_hour < 10) {
          ss << "0";
        }
        ss << ltm->tm_hour;
        ss << ":";
        if (ltm->tm_min < 10) {
          ss << "0";
        }
        ss << ltm->tm_min;
        ss << ":";
        if (ltm->tm_sec < 10) {
          ss << "0";
        }
        ss << ltm->tm_sec;
        ss << "]";
        return ss.str();
        // std::string dateString = "[", tmp = "";
        // tmp = patch::to_string(1900 + ltm->tm_year);
        // dateString += tmp;
        // dateString += "-";
        // tmp = patch::to_string(1 + ltm->tm_mon);
        // if (tmp.length() == 1)
        //     tmp.insert(0, "0");
        // dateString += tmp;
        // dateString += "-";
        // tmp = patch::to_string(ltm->tm_mday);
        // if (tmp.length() == 1)
        //     tmp.insert(0, "0");
        // dateString += tmp;
        // dateString += " ";
        // tmp = patch::to_string(ltm->tm_hour);
        // if (tmp.length() == 1)
        //     tmp.insert(0, "0");
        // dateString += tmp;
        // dateString += ":";
        // tmp = patch::to_string(ltm->tm_min);
        // if (tmp.length() == 1)
        //     tmp.insert(0, "0");
        // dateString += tmp;
        // dateString += ":";
        // tmp = patch::to_string(ltm->tm_sec);
        // if (tmp.length() == 1)
        //     tmp.insert(0, "0");
        // dateString += tmp;
        // dateString += "] ";

        // return dateString;
    }


}
