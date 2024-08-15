#include <string>
#include <set>

class Message {
friend class Folder;
public:
    // default constructor
    explicit Message(const std::string &str = ""): contents(str) {}
    // copy constructor
    Message(const Message&);
    // copy-assignment operator 
    Message& operator=(const Message&);
    // destructor
    ~Message();

    // save this Message to a Foler
    void save(Folder&);
    // remove this Message from a Foler
    void remove(Folder&);
private:
    // actual text of this Message
    std::string contents;
    // Folders that have this Message
    std::set<Folder*> folders;
    // utilities used by copy-control members
        // - add this Message to a Foler that is pointed to by the parameter
    void add_to_Folders(const Message&);
        // - remove this message from every Folder in folders
    void remove_from_Folders();
};

void Message::save(Folder &f)
{
    // add f to folers
    folders.insert(&f);
    // add this Message to f
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    // remove f from folers
    folders.erase(&f);
    // remove this Message to f
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message &m): contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
   remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    for (auto f: rhs.folders)
        f->addMsg(&rhs);
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
}