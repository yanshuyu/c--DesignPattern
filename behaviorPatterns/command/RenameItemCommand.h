#pragma once
#include"ICommand.h"
#include<string>

class FileManager;


class RenameItemCommand: public ICommand {
public:
    RenameItemCommand(FileManager* f, const std::string& oldName, const std::string& newName);

    void execute() override;
    void undo() override;
    void redo() override;

private:
    FileManager* fileManager;
    std::string newName;
    std::string oldName;
};