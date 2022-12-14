# Torodofi - powerfull to-do list manager driven with rofi
![todo + rofi](img/applepen.webp)

## Have fun!
If you find this code useful, I will be glad if you use it in your GPL3-compatible licensed project.

**"Why GPL-3. Author, are you too proud?"**
> Nope. It's just that I'm fighting for free software, and any possibility that someone else is using my code on a project that people, myself included, will have to pay for is unacceptable.
> My code is neither perfect nor revolutionary. But the world is crazy, you know

Any help and criticism is greatly appreciated.

## Overview

Torodofi - Torodofi is a simple tool for managing current tasks, scheduling based on the priorities and deadlines of various tasks. The system of tags and categories is supported.

All tasks are stored in a .md file, and the storage format makes it easy to manually create and edit a task list.

Active tasks:
![active tasks](img/active.png)

Done tasks:
![done tasks](img/done.png)

Edit task:
![edit task](img/edit.png)

Choose tags for new task (multi selection Shift+Enter):
![tags choose](img/tags.png)

Set deadline for task (It's impossible to set earlier then creation date):
![set deadline](img/deadline.png)

## Usage

After installation and first run, you will find a configuration file: **$HOME/.config/torodofi.conf** and an example.md in your $HOME dir.

You can take contents and config examples from **example.cfg**. In this file, you definitely need to set the path to the task file. It is also necessary to create this file. At least one task must be created inside the file.

## Installation

> ArchLinux-based users! There is a package in the AUR =)

Run
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
Then put torodofi executable to PATH.

## Features
- [x] Tags and categories for tasks
- [x] Editing any task field (development has not been stopped)
- [x] Active/Done tasks statuses (development has not been stopped)
- [ ] Assotiations
  - [ ] Associate a task with a running application
  - [ ] Associate a task with an e-mail address
  - [ ] Associate a task with url link
- [ ] integration with cloud services (maybe, maybe)
- [x] Task priorities
  - [x] Sorting tasks by priority
  - [x] Accent colors for 1 and 2 priority tasks
- [ ] Deadline based agenda
- [ ] Deadline & priority based agenda
- [x] Select any menu element with configurable hotkey
- [x] Rofi UI (development has not been stopped)
- [x] YAML-like Configuration file
  - [x] Configurable hotkeys
  - [x] Markdown file with tasks path configurable
  - [x] Custom rofi commandline
- [x] Read and write markdown file with tasks


## Technical information

## Task file format

```markdown
## (priority: 1-3)
- creation_date deadline_date tag1,tag2 category1,category2 text text text
+ creation_date deadline_date tag1,tag2 category1,category2 text text text
```
All tasks are in sections marked with headers of the second level. The title text consists of a single number from 1 to 3, which indicates the priority of tasks placed under the title.

All tasks are list items. Active (not completed) tasks are marked with a +, and completed tasks with a -.

A real example of the task file is [here](example.md).

Each time you exit the program, data is saved and the file is overwritten. This ensures that there is no garbage in the file. Also, after saving, all tasks will be grouped by priority.

## Config file format

The configuration file has YAML-like syntax.
