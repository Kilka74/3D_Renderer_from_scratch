#include "Settings.hpp"
#include "World.hpp"

class FileReader {
public:
    static SettingsImage get_settings(const std::string &filename);
    static WorldImage get_world(const std::string &filename);
};
