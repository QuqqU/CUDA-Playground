#include <mylib/cuda/memory.hpp>
#include <mylib/bench/bench.hpp>

#include <iostream>

int main() {

    qCuda::mem::DeviceMem m(100);
    std::cout << &m << " " << m.d_mem << std::endl;


    qCuda::bench::Tracker tracker;
    tracker.start("a");
    tracker.end("a");
    tracker.start("b");
    tracker.end("b");
    tracker.start("c");
    tracker.end("c");

    qCuda::bench::Tracker::Result min = tracker.min();
    qCuda::bench::Tracker::Result max = tracker.max();
    std::cout << min.duration << " " << min.track_name << std::endl; 
    std::cout << max.duration << " " << max.track_name << std::endl; 
    std::cout << tracker.count() << std::endl; 
    return 0;
}
