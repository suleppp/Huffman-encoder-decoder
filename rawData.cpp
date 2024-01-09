#include "rawData.h"
rawData::rawData(char word,double weight) {
	this->word = word;
	this->weight = weight;
}
rawData::rawData() {
	word = '\0';
	weight = 0;
}