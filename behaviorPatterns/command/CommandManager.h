#pragma once
#include"ICommand.h"
#include<list>


class CommandManager {
public:
    CommandManager(size_t maxCmdHistoryCount = 20);
    ~CommandManager();

    void submit(ICommand* cmd);
    void redo();
    void undo();
    size_t avaliableUndoCommandCount() const;
    size_t avaliableRedoCommandCount() const;

private:
    void clenup();
    void prepareForSubmit();
    void removeCommandAfterSubmit();
private:
    std::list<ICommand*> cmdList;
    size_t maxCmdCount;
    std::list<ICommand*>::iterator effectivedCmd;
};