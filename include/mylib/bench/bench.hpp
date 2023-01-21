#include <chrono>
#include <map>
#include <string>

namespace qCuda {
namespace bench {

class Tracker {
  public:
    using TrackName = std::string;
    using TimePoint = std::chrono::system_clock::time_point;
    using ChronoDuration = std::chrono::duration<double>;
    using Report = std::map<TrackName, TimePoint>;
    struct Result {
        using Duration = double;
        Result(TrackName track_name, ChronoDuration duration);

        TrackName track_name;
        Duration duration;

        inline bool operator<(const Result &rhs) const;
        inline bool operator>(const Result &rhs) const;
    };

    Tracker();
    ~Tracker();

    void start(const TrackName &name);
    void end(const TrackName &name);

    Result min();
    Result max();
    int count();

    Report report;

  private:
    Result _min;
    Result _max;
};

} // namespace bench
} // namespace qCuda