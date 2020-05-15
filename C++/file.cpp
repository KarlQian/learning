#include "file.h"



Message & Message::operator=(const Message &msg)
{
	if (this != &msg)
	{
		remove_from_Folders();
		contents = msg.contents;
		folders = msg.folders;
		add_to_Folders(msg);
		return *this;
	}
	else return *this;
}

void Message::save(Folder &folder)
{
	folders.insert(&folder);
	folder.addMsg(this);
}

void Message::remove(Folder &folder)
{
	folders.erase(&folder);
	folder.remMsg(this);
}

void Message::addFldr(Folder *f)
{
	folders.insert(f);
}

void Message::swap(Message & lhs, Message & rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

void Message::add_to_Folders(const Message & msg)
{
	for (auto f : msg.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
	folders.clear();
}

Folder::Folder(const Folder & rhs)
{
	name = rhs.name;
	messages = rhs.messages;
	add_to_messages(*this);
	
}

Folder & Folder::operator=(const Folder & rhs)
{
	if (this!=&rhs)
	{
		remove_fodler();
		name = rhs.name;
		messages = rhs.messages;
		add_to_messages(rhs);
		return *this;
	}
	else return *this;
}

void Folder::addMsg( Message * msg)
{
	messages.insert(msg);
	//msg->save(*this);
}

void Folder::remMsg(Message * msg)
{
	messages.erase(msg);
	//msg->remove(*this);
}

void Folder::swap(Folder & f1, Folder & f2)
{
	using std::swap;
	for (auto m1 : f1.messages)
		m1->remove(f1);
	for (auto m2 : f2.messages)
		m2->remove(f2);
	swap(f1.name, f2.name);
	swap(f1.messages, f2.messages);
	for (auto m1 : f1.messages)
		m1->save(f1);
	for (auto m2 : f2.messages)
		m2->save(f2);
}

void Folder::add_to_messages(const Folder & folder)
{
	for (Message* m : folder.messages)
		m->addFldr(this);

}

void Folder::remove_fodler()
{
	for (auto m : messages)
		m->remove(*this);
	messages.clear();
}

 void testMessage() 
{
	Message m0;
	Message m1("hello");
	Message m2("world");
	Folder f1("f1");
	Folder f2("f2");
	m1.save(f1);
	m2.save(f2);
	Message m4 = m2;
	
	swap(m1, m4);

}