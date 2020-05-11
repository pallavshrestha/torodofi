#include "TaskContainer.hpp"

using namespace std;

namespace toro {
namespace tasks {

void TaskContainer::_sort_priority() {
  sort(_tasks.begin(), _tasks.end(), cmp_prioroty);
}

// class TaskContainer
TaskContainer::TaskContainer() {}
TaskContainer::TaskContainer(string afilename) {
  size_t pri_del_len = priority_start_point.length();
  string line;
  unsigned priority;
  ifstream file(afilename);

  if (file.is_open()) {
    // Read file: priorities and tasks
    while (getline(file, line)) {
      if (line.find(priority_start_point) == 0) {
        priority = atoi(line.substr(pri_del_len, pri_del_len + 2).c_str());
      } else {
        if (line.find(task_start_point) >= 0) {
          _tasks.push_back(Task(line, priority));
        }
      }
    }
    // If read was successfull, then we can store afilename
    _filename = afilename;
    // Sort read tasks by priority
    _sort_priority();
    // Give ID to sorted tasks
    for (size_t i = 0; i < _tasks.size(); i++) {
      _tasks[i].setId(i);
    }
  } else {
    printf("string afilename: %s\n", afilename.c_str());
    throw std::invalid_argument("File could not be opened");
  }
}

void TaskContainer::Dump(std::string afilename) {
  if (afilename == "") {
    afilename = _filename;
  }
  unsigned priority;
  Task cmptask;
  ofstream file(afilename);

  if (file.is_open()) {
    for (size_t t = 0; t < _tasks.size(); t++) {
      cmptask = _tasks[t];
      if (cmptask.getTask().priority != priority) {
        priority = cmptask.getTask().priority;
        file << priority_start_point + to_string(priority) << endl;
      }
      file << cmptask.toString() << endl;
    }
  } else {
    printf("string afilename: %s\n", afilename.c_str());
    throw std::runtime_error("Bad IO: could not create file");
  }
}

vector<Task> TaskContainer::getTasks() { return _tasks; }

} // namespace tasks
} // namespace toro
