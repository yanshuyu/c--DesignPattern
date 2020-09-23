#include"NewItemCommand.h"  
#include"FileManager.h" 
   
NewItemCommand::NewItemCommand(FileManager* f, const std::string& item):fileManager(f)
,newItem(item) {

}

void NewItemCommand::execute() {
    fileManager->addItem(newItem);
}

void NewItemCommand::undo() {
    fileManager->removeItem(newItem);
}


void NewItemCommand::redo() {
    execute();
}