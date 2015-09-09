#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include "Iterator.h"

namespace containers {

	template <class K, class V> class HashMap {

	public:

		HashMap() {
			hashTable = NULL;
			length = 6;
			loadFactor = 1.5;
			size = 0;
			init();
		}

		class Entry {
		public:
			Entry(const K key, const V value) :key(key), value(value) {
				next = NULL;
			}

			Entry* next;
			K key;
			V value;
		};

		class EntryList {
		public:
			EntryList() {
				first = NULL;
			}

			Entry* first;
		};

		void put(const K& key, const V& data) {
			size_t hash = hashCode(key);
			EntryList* entryList = getEntryListForHash(hash);
			if (entryList != NULL) {
				for (Entry* en = entryList->first; en != NULL; en = en->next) {
					if (en->key == key) {
						en->value = data;
						return;
					}
				}
				Entry* entry = new Entry(key, data);
				entry->next = entryList->first;
				entryList->first = entry;
				size++;
			}
			int threshold = int(length * loadFactor);
			if (size > threshold) {
				resize(length, threshold);
			}
		}

		V get(const K& key) {
			size_t hash = hashCode(key);
			EntryList* entryList = getEntryListForHash(hash);
			if (entryList != NULL) {
				for (Entry* en = entryList->first; en != NULL; en = en->next) {
					if (en->key == key) {
						return en->value;
					}
				}
			}
			return NULL; //what if V == int|float|etc?
		}

		V remove(const K& key) {
			size_t hash = hashCode(key);
			V returnValue = NULL;
			EntryList* entryList = getEntryListForHash(hash);
			if (entryList != NULL) {
				Entry* prev = entryList->first;
				for (Entry* en = entryList->first; en != NULL; en = en->next) {
					if (en->key == key) {
						if (en == prev) { //so "en" is "first"
							entryList->first = en->next;
						} else {
							prev->next = en->next;
						}
						size--;
						returnValue = en->value;
						delete en;
						break;
					}
					prev = en;
				}
			}
			return returnValue;
		}

		~HashMap() {
			EntryList* el = hashTable;
			for (int i = 0; i < length; i++) {
				EntryList* el = hashTable[i];
				Entry* en = el->first;
				while (en != NULL) {
					Entry* next = en->next;
					delete en;
					en = next;
				}
				delete el;
			}
		}

		class MapIterator : public Iterator<V> {
		public:

			MapIterator(EntryList** hashTable, int length) {
				this->table = hashTable;
				this->length = length;
				curEntry = NULL;
				cur = -1;
			}

			V next() {
				EntryList* curEntryList;
				if (curEntry == NULL || curEntry->next == NULL) {
					curEntry = NULL;
					while (cur < length && curEntry == NULL) {
						cur++;
						curEntryList = table[cur];
						curEntry = curEntryList->first;
					}
					if (curEntry == NULL) {
						return NULL;
					}
				} else {
					curEntry = curEntry->next;
				}
				return curEntry->value;
			}

			bool hasNext() {

				Entry* fakeCurrent = curEntry;
				EntryList* curEntryList;

				int _cur = cur;

				if (fakeCurrent == NULL || fakeCurrent->next == NULL) {
					fakeCurrent = NULL;
					while (_cur < length - 1 && fakeCurrent == NULL) {
						_cur++;
						curEntryList = table[_cur];
						fakeCurrent = curEntryList->first;
					}
					return fakeCurrent != NULL;
				} else {
					return true;
				}
			}

			V current() {
				if (curEntry == NULL) {
					return NULL;
				}
				return curEntry->value;
			}

		private:
			EntryList** table;
			int cur;
			int length;
			Entry* curEntry;
		};

		Iterator<V>*  iterator() {
			return new MapIterator(hashTable, length);
		}

	private:
		EntryList** hashTable;
		int length;
		int size;
		float loadFactor;

		EntryList* getEntryListForHash(const size_t hash) {
			int idx = getIndexForHash(hash);
			return hashTable[idx];
		}

		int getIndexForHash(int hash) {
			return hash & (length - 1);
		}

		void init() {
			resize(0, length);
		}

		void resize(int oldLength, int newLength) {
			EntryList** newHashTable = new EntryList*[length];
			for (int i = 0; i < newLength; i++) {
				newHashTable[i] = new EntryList();
			}
			if (hashTable != NULL) {
				for (int i = 0; i < oldLength; i++) {
					EntryList* curList = hashTable[i];

					for (Entry* en = curList->first; en != NULL; en = en->next) {
						K key = en->key;
						V data = en->value;
						size_t hash = hashCode(key);
						int idx = hash & (newLength - 1);
						EntryList* newList = newHashTable[idx];

						Entry* entry = new Entry(key, data);
						entry->next = newList->first;
						newList->first = entry;
					}

				}
				delete hashTable;
			}
			this->length = newLength;
			this->hashTable = newHashTable;
		}

	};

	template <class K>
	size_t hashCode(const K& key) {
		return -1;
	}

	//basic specifications

	template <> size_t hashCode<std::string>(const std::string& key) {
		size_t hash = 0;
		for (int i = 0; i < key.length(); i++) {
			char c = key.at(i);
			hash = hash * 31 + int(c);
		}
		return hash;
	}

} //containers


#endif // HASHMAP_H