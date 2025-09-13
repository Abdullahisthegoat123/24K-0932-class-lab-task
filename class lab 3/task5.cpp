#include <iostream>
#include <string>
using namespace std;

class Track {
public:
    string name;
    Track* next;

    Track(string n) : name(n), next(nullptr) {}
};

class Playlist {
private:
    Track* head;

public:
    Playlist() : head(nullptr) {}

    void add(string n) {
        Track* t = new Track(n);
        if (head == nullptr) {
            head = t;
            head->next = head;
            return;
        }
        Track* p = head;
        while (p->next != head) p = p->next;
        p->next = t;
        t->next = head;
    }

    void show() const {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Track* p = head;
        do {
            cout << p->name << " -> ";
            p = p->next;
        } while (p != head);
        cout << "(repeat)" << endl;
    }

    void playSongs(int count) const {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Track* p = head;
        for (int i = 0; i < count; i++) {
            cout << "Now Playing: " << p->name << endl;
            p = p->next;
        }
    }
};

int main() {
    Playlist music;

    music.add("baby shark");
    music.add("Husn");
    music.add("phonk");

    cout << "Current Playlist: ";
    music.show();

    cout << "\nplayback (7 times):" << endl;
    music.playSongs(7);

    return 0;
}
