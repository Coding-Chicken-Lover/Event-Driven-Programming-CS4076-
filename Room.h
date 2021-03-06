#ifndef ROOM_H_
#define ROOM_H_

#include <QString>
#include <QPixmap>
#include <string>
#include <map>
#include <vector>
#include "item.h"
#include "notes.h"
#include "keys.h"

using namespace std;
using std::vector;

class Room {

    friend bool operator !=(keys &, Room &);

private:
    QString description;
    QString viewPath;
    QString keyID;
    vector<Room*> exits;
    QString exitString();
    vector<Item*> itemsInRoom;
    QPixmap roomInMapImage;
    bool upstairs;
    bool downstairs;
    bool locked;

public:
    Room(QString = "", QString = "", QString = "", bool = false, bool = false, bool = false, QString = "");
    ~Room();
    void setExits(vector<Room*>&);
    void addNote(notes*);
    void addKeys(keys*);
    vector<Room*> getExits();
    vector<Item*> getItems();
    QString shortDescription();
    QString longDescription();
    bool canGoUp();
    bool canGoDown();
    bool checkIfLocked();
    QPixmap getPixmap();
    QString getViewPixmap();
    QString getNotepath();
    void clearRoomOfItems();
    bool checkUnlockDoor(keys*);
    void setLocked(bool);
};

#endif
