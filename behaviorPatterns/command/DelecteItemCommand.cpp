#include"DelecteItemCommand.h"
#include"FileManager.h"


DelecteItemCommand::DelecteItemCommand(FileManager* f, const std::string& item):fileManager(f) 
,item(item) {

}

void DelecteItemCommand::execute() {
    fileManager->removeItem(item);
}

void DelecteItemCommand::undo() {
    fileManager->addItem(item);
}

void DelecteItemCommand::redo() {
    execute();
}
