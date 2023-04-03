#include <iostream>
#include <string>

using namespace std;

string format_duration(int seconds) {
    string result;
    int time = seconds;
    int count;
    int parts = 0;
    if (time == 0) {
        return "now";
    }
    while (time > 0) {
        if (time >= 31536000) {
            count = 0;
            while (31536000 * count <= time) {
                count++;
            }
            count--;
            time -= count * 31536000;
            if (count > 1) {
                result += to_string(count) + " years, ";
                parts++;
            }
            if (count == 1) {
                result += to_string(count) + " year, ";
                parts++;
            }
        }
        if (time >= 86400) {
            count = 0;
            while (86400 * count <= time) {
                count++;
            }
            count--;
            time -= count * 86400;
            if (parts > 0 && time == 0) {
                result.pop_back();
                result.pop_back();
                result += " and ";
            }
            if (count > 1) {
                result += to_string(count) + " days, ";
                parts++;
            }
            if (count == 1) {
                result += to_string(count) + " day, ";
                parts++;
            }         
        }
        if (time >= 3600) {
            count = 0;
            while (3600 * count <= time) {
                count++;
            }
            count--;
            time -= count * 3600;
            if (parts > 0 && time == 0) {
                result.pop_back();
                result.pop_back();
                result += " and ";
            }
            if (count > 1) {
                result += to_string(count) + " hours, ";
                parts++;
            }
            if (count == 1) {
                result += to_string(count) + " hour, ";
                parts++;
            }           
        }
        if (time >= 60) {
            count = 0;
            while (60 * count <= time) {
                count++;
            }  
            count--;
            time -= count * 60;
            if (parts > 0 && time == 0) {
                result.pop_back();
                result.pop_back();
                result += " and ";
            }
            if (count > 1) {
                result += to_string(count) + " minutes, ";
                parts++;
            }
            if (count == 1) {
                result += to_string(count) + " minute, ";
                parts++;
            }   
        }
        if (time >= 1) {
            if (parts > 0) {
                result.pop_back();
                result.pop_back();
                result += " and ";
            }
            if (time == 1) {
                result += to_string(time) + " second, ";
                break;
            }
            result += to_string(time) + " seconds, ";
            break;
        }
        
    }
    result.pop_back();
    result.pop_back();
    return result;
}

int main()
{
    cout << format_duration(0) << endl;
    cout << format_duration(1) << endl;
    cout << format_duration(62) << endl;
    cout << format_duration(120) << endl;
    cout << format_duration(3662) << endl;
    cout << format_duration(999928662) << endl;
}
