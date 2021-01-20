// g++ -std=c++11 -pthread -o foo foo.cpp

#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
 
map<string, string> pages;
// mutex pages_mutex;
 
void save_page(const string &url)
{
    // cout << this_thread::get_id << endl;
    this_thread::sleep_for(chrono::seconds(2));
    string result = "fake content";
 
    // lock_guard<mutex> guard(pages_mutex);
    pages[url] = result;
}
 
int main() 
{
    thread t1(save_page, "http://foo");
    thread t2(save_page, "http://bar");
    // cout << "t1 done" << endl;
    t1.join();
    t2.join();
    // cout << "t2 done" << endl;
 
    // safe to access pages without lock now, as the threads are joined
    for (const auto &pair : pages) {
        cout << pair.first << " => " << pair.second << '\n';
    }
    return 0;
}