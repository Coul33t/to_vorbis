#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "ERROR: need the file name as an argument." << std::endl;
        return -1;
    }
    
    std::string filename = argv[1];

    std::cout << filename << std::endl;
    
    std::string command_pt1 = "ffmpeg -i ";
    std::string command_pt2 = " -c:a libvorbis ";


    size_t pos_of_dot = filename.find_last_of(".");

    if (pos_of_dot == std::string::npos) {
        std::cerr << "ERROR: extension not found (be sure that the file name has an extension)." << std::endl;
        return -1;
    }

    std::string final_command = command_pt1 + filename + command_pt2 + filename.substr(0, pos_of_dot) + ".ogg";
    system(final_command.c_str());

    return 0;
}