// #include <vector>
// #include <chrono>
#include <mylib/bench/bench.hpp>

// #include <utility>

namespace qCuda {
namespace bench {

Tracker::Result::Result(TrackName track_name, ChronoDuration duration)
    : track_name(track_name) {
    this->duration = duration.count();
}

inline bool Tracker::Result::operator<(const Result &rhs) const {
    return duration < rhs.duration;
}

inline bool Tracker::Result::operator>(const Result &rhs) const {
    return duration > rhs.duration;
}

Tracker::Tracker()
    : _min(Result("Empty", ChronoDuration::max())),
      _max(Result("Empty", ChronoDuration::min())) {}

Tracker::~Tracker() {}

void Tracker::start(const TrackName &name) {
    report[name] = std::chrono::system_clock::now();
}

void Tracker::end(const TrackName &name) {
    TimePoint start_time = report[name];
    TimePoint end_time = std::chrono::system_clock::now();
    ChronoDuration duration = end_time - start_time;
    Result result = {name, duration};

    _min = std::min(_min, result);
    _max = std::max(_max, result);
}

Tracker::Result Tracker::min() { return _min; }
Tracker::Result Tracker::max() { return _max; }
int Tracker::count() { return report.size(); }

} // namespace bench
} // namespace qCuda