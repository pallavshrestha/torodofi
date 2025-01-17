#pragma once

#include <functional>

#include "Config/Config.hpp"
#include "Tasks/Task.hpp"
#include "Tasks/TaskContainer.hpp"
#include "logic.hpp"
#include "types.hpp"

namespace toro {
namespace app {

const std::string home_directory = getenv("HOME");
const std::string config_file_name = home_directory + "/.config/torodofi.conf";

const std::string color0 = "<span color='#8fbcbb'>"; // hotkeys [nord7]
const std::string color1 = "<span color='#d08770'>"; // deadline [nord12]
const std::string color2 = "<span color='#eceff4'>"; // white [nord6]
const std::string color3 = "<span color='#b8dee9'>"; // grey  [nord4]
const std::string span = "</span>";

const std::string msg0 = "\nChoose the necessary options from the listed "
                         "below:\nShift+Enter for multiple selection\n";
const std::string rofi_options_delimiter = tasks::string_repr_delimiter;
const std::string menu_back = "< Back";
const std::string menu_empty = "---";

const std::vector<std::string> any_menu_actions = {};

const std::vector<std::string> one_task_actions = {"1 Toggle", "2 Edit"};

const std::vector<std::string> edit_task_options = {
    "1 Text", "2 Deadline", "3 Priority", "4 Tags", "5 Categories", "6 Delete"};

class App {
protected:
  config::Config _objConfig;
  tasks::TaskContainer _objTasks;
  std::string active_tasks_caption;

  std::string kb_customs;
  std::string kb_selections;

  void _exit();
  // Read configuration file
  void _readConfig(const std::string& afilename);
  // Read .md file with tasks
  void _readTasks(const std::string& afilename);

  // Compose cmdline for task-base menus
  std::string _task_based_menu(tasks::Task atask,
                               std::vector<std::string> add_menu,
                               bool any_menu = true,
                               const std::string& custom_rofi_keys = "");
  std::string _caption_based_menu(const std::string& acaption, const std::string& add_menu,
                                  const std::string& aprompt, bool any_menu = true,
                                  const std::string& custom_rofi_keys = "");
  // Show rofi window with active tasks list
  // return selected fields string
  types::returnstatus _showTasks(bool is_active);
  // Show rofi window with one Task information
  // return selected action string
  types::returnstatus _showOneTask(unsigned aid, bool is_active);
  // Edit selected by id task
  void _editTask(unsigned aid, bool is_active);
  // Choose Tags
  std::vector<std::string> _chooseTags(const std::string& acaption);
  // Choose Categories
  std::vector<std::string> _chooseCategories(const std::string& acaption);
  // Choose date
  types::date _chooseDate(const std::string& acaption,
                          types::date adate = types::date());
  // Input text
  std::string _chooseText(const std::string& acaption, const std::string& atext);

  template <typename T>
  T _chooseFromVector(std::vector<T> avector, const std::string& acaption);

public:
  // Constructor
  App(std::string aconfigfilename = "");
  // Start Application
  void Start();
};

} // namespace app
} // namespace toro
