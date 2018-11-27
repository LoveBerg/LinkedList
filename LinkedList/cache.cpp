#define _CRT_SECURE_NO_WARNINGS
#include "cache.h"


cache::cache() {
	linkedlist = new LinkedList();
	//linkedlist->count = 0;
	linkedlist->head = NULL;

}
void cache::AddToCache(int id, std::string txt) {
	char* destination = new char[txt.length() + 1];
	strcpy(destination, txt.c_str());
	addNewNode(this->linkedlist, id, destination);


}
std::string cache::GetFromCache(int id) {
	char* cachetxt;

	cachetxt = getDestination(this->linkedlist, id);
	if (cachetxt == NULL)
		return "";
	std::string cachestring(cachetxt);
	return cachestring;
}
