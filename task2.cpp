#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

void compress(const string& input, const string& output) {
    ifstream in(input, ios::binary);
    ofstream out(output, ios::binary);

    char ch;
    while (in.get(ch)) {
        // Simulated compression delay
        this_thread::sleep_for(chrono::milliseconds(1));
        out.put(ch); // Just copying for demo
    }

    in.close();
    out.close();
    cout << "Compression done.\n";
}

void decompress(const string& input, const string& output) {
    ifstream in(input, ios::binary);
    ofstream out(output, ios::binary);

    char ch;
    while (in.get(ch)) {
        this_thread::sleep_for(chrono::milliseconds(1));
        out.put(ch); // Just copying back
    }

    in.close();
    out.close();
    cout << "Decompression done.\n";
}

int main() {
    string source = "data.txt";
    string compressed = "data.cmp";
    string decompressed = "data_restored.txt";

    thread t1(compress, source, compressed);
    thread t2(decompress, compressed, decompressed);

    t1.join();
    t2.join();

    return 0;
}
