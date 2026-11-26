#include "functions.hpp"
#include <cstdlib>
#include <filesystem>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::string dot_git_fol_name = ".time_machine";
std::vector<std::string> subdir = {".time_machine/objects/",
                                   ".time_machine/commits/"};
void explain(std::string_view note,
             std::filesystem::filesystem_error const &ex) {
  std::cout << note << " exception:\n"
            << "what(): " << ex.what() << '\n'
            << "path1(): " << ex.path1() << ", path2(): " << ex.path2()
            << "\n\n";
}
void init() {
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
    // calling a fundtion that createsa ll the
    if (std::filesystem::create_directory(dot_git_fol_name)) {
      for (const auto &sub : subdir) {
        std::filesystem::create_directory(sub);
      }
    }
  } catch (std::filesystem::filesystem_error &e) {
    explain("fs::filesystem -> ", e);
  }
}
std::vector<std::string> arr_hashes;
void commit() {
  for (std::filesystem::recursive_directory_iterator it(dot_git_fol_name), end;
       it != end; ++it) {
    if (!std::filesystem::is_directory(it->path())) {
      arr_hashes.push_back(it->path().string());
    }
  }
  for (auto &x : arr_hashes) {
    std::string cmd = "openssl sha256 " + x + " > " + x + ".txt";
    system(cmd.c_str());
  }

  std::string kmd = "echo *";
  system(kmd.c_str());
}
