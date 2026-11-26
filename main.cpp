#include "functions.hpp"
#include <filesystem>
#include <iostream>
#include <system_error>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "time-machine not a command" << std::endl;
    return 1;
  }

  std::string cmd = argv[1];

  if (cmd == "init") {
    std::filesystem::path target_path = (argc >= 3)
                                            ? std::filesystem::path(argv[2])
                                            : std::filesystem::current_path();
    std::filesystem::path root_path;
    try {
      root_path = std::filesystem::weakly_canonical(target_path);
    } catch (const std::filesystem::filesystem_error &e) {
      std::cerr << "error making the repo " << e.what() << std::endl;
    }

    std::filesystem::path my_git = root_path / ".time-machine";
    std::vector<std::string> sub_dirs = {"objects", "refs"};
    for (const auto &dir : sub_dirs) {
      std::error_code ec;
      std::filesystem::create_directories(my_git / dir, ec);
      if (ec) {
        std::cout << "Fatal : some error occured" << std::endl;
        return 1;
      }
    }

    std::cout << "Initialised the .time-machine repo my dear master"
              << std::endl;
    return 0;
  } else {
    std::cerr << "My dear master you have not written any other command yet so "
                 "go write them and than make use of them"
              << std::endl;
    return 1;
  }
  return 0;
}
