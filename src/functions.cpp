#include "functions.hpp"
void init() {
  std::string dot_git_fol_name = ".time_machine";
  for (const auto &file :
       std::filesystem::directory_iterator(std::filesystem::current_path())) {
    if (file.path().filename() == dot_git_fol_name) {
      std::cout
          << "Sorry Dear Master we were unable to make the timeline because "
          << "there is already a timeline existing in the current time space "
          << "although here is the file path of that file anyway ->"
          << file.path().string() << std::endl;
      return;
    }
  }

  try {
    if (std::filesystem::create_directories(dot_git_fol_name)) {
      std::cout << "Master your timeline has started you can start taking "
                << "snapshots for it" << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Error creating directory: " << e.what() << std::endl;
  }
}
