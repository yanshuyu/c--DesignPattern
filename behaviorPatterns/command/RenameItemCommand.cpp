#include"RenameItemCommand.h"
#include"FileManager.h"



RenameItemCommand::RenameItemCommand(FileManager* f, const std::string& oldName, const std::string& newName):fileManager(f)
, oldName(oldName)
, newName(newName) {

}

void RenameItemCommand::execute() {
    fileManager->renameItem(oldName, newName);
}

void RenameItemCommand::undo() {
    fileManager->renameItem(newName, oldName);
} 

void RenameItemCommand::redo() {
    execute();
}