#include<iostream>
#include"FileManager.h"
#include"CommandManager.h"
#include"NewItemCommand.h"
#include"DelecteItemCommand.h"
#include"RenameItemCommand.h"


using std::cout;
using std::endl;


int main() {
    FileManager fMgr;
    CommandManager cmdMgr(3);

    auto myImage = "./images/my_image.png";
    auto mySong = "./music/my_song.mp3";
    auto myVideo = "./video/my_video.mp4";
    auto myText = "./document/my_text.txt";
    auto myXML = "./download/www.baidu.com.html";
    auto myProject = "./document/dev/designPattern_c++.sln";

    auto myImageRename = "./images/my_image_rename.png";
    auto myXMLRename = "./download/www-baidu-com-rename.html";

    cmdMgr.submit(new NewItemCommand(&fMgr, myImage));
    cmdMgr.submit(new NewItemCommand(&fMgr, mySong));
    cmdMgr.submit(new NewItemCommand(&fMgr, myVideo));
    cmdMgr.submit(new NewItemCommand(&fMgr, myText));
    cmdMgr.submit(new NewItemCommand(&fMgr, myXML));
    cmdMgr.submit(new NewItemCommand(&fMgr, myProject));

    cout << "my files: " << fMgr << endl << endl;

    while (cmdMgr.avaliableUndoCommandCount() > 0) {
        cmdMgr.undo();
        cout << "after undo my files: " << fMgr << endl << endl;
    }
    
    while (cmdMgr.avaliableRedoCommandCount() > 0) {
        cmdMgr.redo();
        cout << "after redo my files: " << fMgr << endl << endl;
    }
    
    cmdMgr.submit(new RenameItemCommand(&fMgr, myImage, myImageRename));
    cmdMgr.submit(new RenameItemCommand(&fMgr, myXML, myXMLRename));

    cout << "after rename my files: " << fMgr << endl << endl;

    return 0;
}

