#ifndef FILEH
#define FILEH
#include <string>
#include<set>
using namespace std;
class Folder;
class Message {
public:
	Message(const string& _str="") :contents(_str) {}
	Message(const Message&_msg) :contents(_msg.contents), folders(_msg.folders) 
	{
		add_to_Folders(_msg);
	}
	Message& operator=(const Message&);
	~Message() { remove_from_Folders(); }
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder*);
	void swap(Message& lhs, Message& rhs);

private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message& msg);
	void remove_from_Folders();
};
class Folder {
public:
	Folder(const string& folder = "") :name(folder){}
	Folder(const Folder& rhs);
	Folder& operator=(const Folder& rhs);
	void addMsg( Message* msg);
	void remMsg( Message* msg);
	~Folder() { remove_fodler(); }
	void swap(Folder& f1, Folder&f2);
private:
	string name;
	set<Message*> messages;
	void add_to_messages(const Folder& folder);
	void remove_fodler();
};

#endif
