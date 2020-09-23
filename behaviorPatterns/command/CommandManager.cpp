#include"CommandManager.h"
#include<iterator>
#include<algorithm>

CommandManager::CommandManager(size_t maxCmdHistoryCount):maxCmdCount(maxCmdHistoryCount)
, effectivedCmd(cmdList.end()) {
}

CommandManager::~CommandManager() {
    clenup();
}

void CommandManager::submit(ICommand* cmd) {
    prepareForSubmit();
    cmd->execute();
    cmdList.push_back(cmd);
    effectivedCmd = std::prev(cmdList.end());
    removeCommandAfterSubmit();
}

void CommandManager::prepareForSubmit() {
    if (cmdList.empty() || effectivedCmd == std::prev(cmdList.end()))
        return;

    auto fst = effectivedCmd == cmdList.end() ? cmdList.begin() : std::next(effectivedCmd);
    auto lst = cmdList.end();

    std::for_each(fst, lst, [](ICommand* cmd){
        delete cmd;
    });
    cmdList.erase(fst, lst);
}

void CommandManager::redo() {
    if (cmdList.empty() || effectivedCmd == std::prev(cmdList.end()))
        return;
   auto nextCmd = std::next(effectivedCmd);
   (*nextCmd)->redo();
   effectivedCmd = nextCmd;
}

void CommandManager::undo() {
    if (cmdList.empty() || effectivedCmd == cmdList.end())
        return;

    (*effectivedCmd)->undo();
    effectivedCmd = std::prev(effectivedCmd);
}


void CommandManager::clenup() {
    std::for_each(cmdList.begin(), cmdList.end(), [](ICommand* cmd){
        delete cmd;
    });
    cmdList.clear();
    effectivedCmd = cmdList.end();
}


size_t CommandManager::avaliableUndoCommandCount() const {
    if (cmdList.empty() || effectivedCmd == cmdList.end())
        return 0;
    decltype(cmdList)::const_iterator last = std::next(effectivedCmd);
    return std::distance(cmdList.begin(), last);
}


size_t CommandManager::avaliableRedoCommandCount() const {
    if (cmdList.empty() || effectivedCmd == std::prev(cmdList.end()))
        return 0;
    decltype(cmdList)::const_iterator fst = std::next(effectivedCmd);
    return std::distance(fst, cmdList.end());
}


void CommandManager::removeCommandAfterSubmit() {
    while(cmdList.size() > maxCmdCount) {
        cmdList.pop_front();
    }
}