#pragma once
#include"ICommand.h"
#include<string>

class FileManager;


class DelecteItemCommand: public ICommand {
public:
    DelecteItemCommand(FileManager* f, const std::string& item);

    void execute() override;
    void undo() override;
    void redo() override;

private:
    FileManager* fileManager;
    std::string item;
};