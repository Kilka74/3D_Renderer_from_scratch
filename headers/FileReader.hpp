#include "Settings.hpp"
#include "World.hpp"

class FileReader {
public:
    static Settings get_settings(const std::string &filename);
    static World get_world(const std::string &filename);
};
