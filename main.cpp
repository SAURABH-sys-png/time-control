#include "functions.hpp"
#include <filesystem>
#include <iostream>
#include <system_error>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "The time machine hums, but you haven't told it where to go. "
                 "Give it a command!"
              << std::endl;
    return 1;
  }

  std::string cmd = argv[1];
  //--------------------------------------------------------------------------------------->
  // init command
  if (cmd == "init") {
    std::filesystem::path target_path = (argc >= 3)
                                            ? std::filesystem::path(argv[2])
                                            : std::filesystem::current_path();
    std::filesystem::path root_path;
    try {
      root_path = std::filesystem::weakly_canonical(target_path);
    } catch (const std::filesystem::filesystem_error &e) {
      std::cerr
          << "The temporal coordinates went haywire while building the repo: "
          << e.what() << std::endl;
    }
    // Check for any existing .time_machine repo inside of the program

    for (const auto &file :
         std::filesystem::recursive_directory_iterator(root_path)) {
      if (std::filesystem::is_directory(file.path()) &&
          file.path().string() == root_path / ".time-machine") {
        std::cout << "A time machine is already parked here, master. Two of "
                     "them would tear the timeline!"
                  << std::endl;
        return 1;
      }
    }
    // well we hae checked if the git init already in there or not
    std::filesystem::path my_git = root_path / ".time-machine";
    std::vector<std::string> sub_dirs = {"objects", "refs"};
    for (const auto &dir : sub_dirs) {
      std::error_code ec;
      std::filesystem::create_directories(my_git / dir, ec);
      if (ec) {
        std::cout << "Catastrophe! The timeline fractured while we were laying "
                     "the foundations."
                  << std::endl;
        return 1;
      }
    }

    std::cout << "The time machine is fueled and ready, my dear master. Your "
                 "history begins now."
              << std::endl;
    return 0;
  }
  // ----------------------------------------------------------------------------->
  // Commit command
  else if (cmd == "commit") {

    // check for the initialiased the repo
    bool has_init = 0;
    for (const auto &file : std::filesystem::recursive_directory_iterator(
             std::filesystem::current_path())) {
      if (file.path() == std::filesystem::current_path() / ".time-machine")
        has_init = 1;
    }
    if (!has_init) {
      std::cout << "Do a git init" << std::endl;
      return 1;
    }

    // to be removed
    std::vector<std::string> temp_lsit;
    for (const auto &file : std::filesystem::recursive_directory_iterator(
             std::filesystem::current_path())) {
      if (std::filesystem::is_regular_file(file.path())) {
        temp_lsit.push_back(file.path().string());
      }
    }

    // to be removed
    for (const auto &x : temp_lsit) {
      std::cout << x << " " << std::endl;
    }
    // the point is how do we sha256 the file contents

    return 0;

  }
  //---------------------------------------------------------------------------->
  else {
    std::cerr
        << "My dear master, this machine knows only one destination so far. "
           "Go build more commands, then come back and put them to use!"
        << std::endl;
    return 1;
  }
  return 0;
}
