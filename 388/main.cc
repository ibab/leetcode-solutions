#include <vector>
#include <iostream>

struct Segment {
    Segment(int init_, int size_, int level_)
        : init(init_), size(size_), level(level_) {}
    int init;
    int size;
    int level;
};

std::ostream& operator<<(std::ostream& os, Segment& s) {
    os << "{" << s.init << ", " << s.size << ", " << s.level << "}";
    return os;
}

template <typename t>
std::ostream& operator<<(std::ostream& os, std::vector<t>& vec) {
    os << "[";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

class Solution {
public:
    // Converts the displayed string into segments
    std::vector<Segment> parseSegments(std::string& input) {
        std::vector<Segment> segments;
        for (int i = 0; i < input.size(); i++) {
            int level = 0;
            int size = 0;
            // Collect level
            while (input[i] == '\t') {
                i++;
                level++;
            }
            int init = i;
            // Collect path segment
            while (input[i] != '\n' && i < input.size()) {
                i++;
                size++;
            }
            if (size > 0) {
                segments.push_back(Segment(init, size, level));
            }
        }
        return segments;
    }

    // Converts displayed segments into paths
    std::vector<std::vector<Segment>> fuseSegments(std::vector<Segment>& segments) {
        std::vector<std::vector<Segment>> result;
        std::vector<Segment> stack;
        int current_level = 0;
        stack.push_back(segments.front());
        for (int i = 1; i < segments.size(); i++) {
            Segment& s = segments[i];
            if (s.level <= current_level) {
                result.push_back(std::vector<Segment>(stack.begin(), stack.end()));
                for (int j = 0; j < current_level - s.level + 1; j++) {
                    stack.pop_back();
                }
            }
            current_level = s.level;
            stack.push_back(s);
        }
        result.push_back(std::vector<Segment>(stack.begin(), stack.end()));
        return result;
    }

    // Finds the longest path in a list of paths and returns its length
    int findMaxPath(std::string input, std::vector<std::vector<Segment>>& fused) {
        int max = 0;
        for (auto& path: fused) {
            int size = 0;
            for (Segment& s: path) {
                size += s.size;
            }
            // Check for file extension
            Segment& s = path[path.size() - 1];
            size_t result = input.substr(s.init, s.size).find(".");
            if (result == std::string::npos) {
                continue;
            }
            // Add path delimiters
            size += path.size() - 1;
            if (size > max) {
                max = size;
            }
        }
        return max;
    }

    int lengthLongestPath(std::string input) {
        std::vector<Segment> segments = parseSegments(input);
        std::vector<std::vector<Segment>> fused = fuseSegments(segments);
        return findMaxPath(input, fused);
    }
};

int main() {
    Solution solution;
    for (int i = 0; i < 100000; i++) {
        solution.lengthLongestPath("skd\n\talskjv\n\t\tlskjf\n\t\t\tklsj.slkj\n\t\tsdlfkj.sdlkjf\n\t\tslkdjf.sdfkj\n\tsldkjf\n\t\tlskdjf\n\t\t\tslkdjf.sldkjf\n\t\t\tslkjf\n\t\t\tsfdklj\n\t\t\tlskjdflk.sdkflj\n\t\t\tsdlkjfl\n\t\t\t\tlskdjf\n\t\t\t\t\tlskdjf.sdlkfj\n\t\t\t\t\tlsdkjf\n\t\t\t\t\t\tsldkfjl.sdlfkj\n\t\t\t\tsldfjlkjd\n\t\t\tsdlfjlk\n\t\t\tlsdkjf\n\t\tlsdkjfl\n\tskdjfl\n\t\tsladkfjlj\n\t\tlskjdflkjsdlfjsldjfljslkjlkjslkjslfjlskjgldfjlkfdjbljdbkjdlkjkasljfklasjdfkljaklwejrkljewkljfslkjflksjfvsafjlgjfljgklsdf.a");
    }
}
