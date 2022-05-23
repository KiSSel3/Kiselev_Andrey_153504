#include "stringlib.h"

StringLib::StringLib() {
    data = new char[1];
    sizee = 1;
    data[0] = '\0';
}

StringLib::StringLib(const StringLib& s) {
    unsigned i, j;
    for (i = 0; s.data[i] != '\0'; i++);
    data = new char[i + 1];
    sizee = i + 1;
    for (j = 0; j < sizee; j++)data[j] = s.data[j];
}

StringLib::StringLib(const char* cs) {
    unsigned i, j;
    for (i = 0; cs[i] != '\0'; i++);
    sizee = i + 1;
    data = new char[sizee];
    for (j = 0; j < (sizee - 1); j++)data[j] = cs[j];
    data[i] = '\0';
}

StringLib::StringLib(const StringLib& s, const size_t& pos, const size_t& n) {
    unsigned i, j;
    data = new char[n + 1];
    sizee = n + 1;
    for (i = pos, j = 0; i < (pos + n); i++, j++)data[j] = s.data[i];
    data[n] = '\0';
}

StringLib::StringLib(const char* cs, const size_t& n) {
    unsigned i;
    for (i = 0; cs[i] != '\0'; i++);
    sizee = n + 1;
    data = new char[sizee];
    for (i = 0; i < (sizee - 1) && i < n; i++)data[i] = cs[i];
    data[n] = '\0';
}

StringLib::StringLib(const size_t& n, const char& c) {
    unsigned i;
    sizee = n + 1;
    data = new char[sizee];
    for (i = 0; i < n; i++)data[i] = c;
    data[n] = '\0';
}

StringLib::~StringLib() {
    if (this->data != NULL)
        delete[] this->data;
}


char* StringLib::getText() {
    return data;
}

void StringLib::setText(char* text) {
    delete[] this->data;

    this->sizee = strlen(text);
    this->data = new char[this->sizee];

    strncpy(this->data, text, this->sizee);
}

size_t StringLib::getLength() const {
    return strlen(this->data);
}

void StringLib::setLength(size_t sizee) {
    size_t old_length = this->getLength();
    char* old_data = this->data;

    this->sizee = sizee;
    this->data = new char[sizee];

    for (size_t i = 0; i < sizee; i++) {
        if (i < old_length) {
            this->data[i] = old_data[i];
        }
        else {
            this->data[i] = '\0';
        }
    }

    delete[] old_data;

    this->data[sizee] = '\0';
}

void StringLib::add(const StringLib& text) {
    size_t new_size = this->sizee + text.sizee;
    setLength(new_size);

    size_t length = getLength();
    for (size_t i = length; i < new_size; i++) {
        this->data[i] = text.data[i - length];
    }
}

char StringLib::at(size_t pos) const {
    if (pos > getLength()) {
        return '\0';
    }
    return data[pos];
}

bool StringLib::compare(const StringLib& string) const {
    return strcmp(this->data, string.data) == 0;
}

char StringLib::operator[](size_t pos) {
    return this->at(pos);
}

StringLib operator+(const StringLib& string1, const StringLib& string2) {
    StringLib string = StringLib(string1);
    string.add(string2);

    return string;
}

bool operator==(const StringLib& string1, const StringLib& string2) {
    return string1.compare(string2);
}


bool StringLib::empty() {
    if (sizee == 0) return 1;
    return 0;
}

void StringLib::clear() {
    if (this->data != NULL)
        delete[] this->data;
    sizee=0;
}
size_t StringLib::capacity() {
    return sizee;
}

void StringLib::resize(size_t sizee, char c = '\0') {
    char* old_data = this->data;
    if (sizee > this->sizee) {
        this->data = new char[sizee];
        strcmp(this->data, old_data);
        for (size_t a = this->sizee; a < sizee; a++)
            this->data[a] = c;
    }
    else {
        this->data = new char[sizee];
        for (size_t a = 0; a < sizee; a++)
            this->data[a] = old_data[a];
    }
    this->sizee = sizee;
    delete[] old_data;
}

size_t StringLib::max_size() {
    return INT_MAX;
}

size_t StringLib::lenght() {
    return this->sizee;
}

size_t StringLib::size() {
    return this->sizee;
}

char StringLib::back() const {
    if (this->sizee > 0) {
        return this->data[this->sizee - 1];
    }
}

char StringLib::front() const {
    if (this->sizee > 0) {
        return this->data[0];
    }
}

void StringLib::append(StringLib& string) {
    char* old_data = this->data;
    this->data = new char[sizee + string.size()+1];
    for (size_t a = 0; a < sizee; a++) this->data[a] = old_data[a];
    for (size_t a = 0; a < string.size(); a++) this->data[a + sizee] = old_data[a];
    this->sizee = sizee + string.size();
    data[sizee + string.size()]='\0';
    delete[] old_data;
}


void StringLib::push_back(char q) {
    char* old_data = this->data;
    this->data = new char[sizee + 2];
    for (size_t a = 0; a < sizee; a++) this->data[a] = old_data[a];
    this->data[sizee] = q;
    this->data[sizee+1] = '\0';
    this->sizee = sizee + 1;
    delete[] old_data;
}

StringLib& StringLib::assign(const char* cs, const size_t& n) {
    unsigned i;
    this->sizee = n + 1;
    this->data = new char[n + 1];
    for (i = 0; i < (this->sizee - 1); i++)
        this->data[i] = cs[i];
    this->data[this->sizee - 1] = '\0';
    return *this;
}

StringLib& StringLib::insert(const size_t& pos, const StringLib& s) {
    StringLib str(data);
    unsigned i, j;
    sizee = s.sizee + str.sizee - 1;
    delete[] data;
    data = new char[sizee];
    for (i = 0; i < pos; i++)
        data[i] = str.data[i];
    for (i = pos, j = 0; j < (s.sizee - 1); i++, j++)
        data[i] = s.data[j];
    for (i = s.sizee + pos - 1, j = pos; i < sizee; i++, j++)
        data[i] = str.data[j];
    return *this;
}

size_t StringLib::rfind(const char* s2) {
    const size_t ln1 = strlen(data);
    const size_t ln2 = strlen(s2);

    if (ln1 < ln2)
        return size_t(-1);

    for (auto* it = data + ln1 - ln2, *end = data - 1; it != end; --it)
        if (strncmp(it, s2, ln2) == 0)
            return size_t(it - data);

    return size_t(-1);
}

int StringLib::find(StringLib textForFind) {

    size_t j = 0;
    for (size_t i = 0; i < size(); i++) {
        if (data[i] == textForFind[j])
            j++;
        else if (j == textForFind.size())
            return j;
        else
            j = 0;
    }
    return -1;
}

StringLib& StringLib::erase(const size_t& pos, const size_t& n) {
    unsigned i, j;
    StringLib str(data);
    sizee = str.sizee - n;
    delete[] data;
    data = new char[sizee];
    for (i = 0; i < pos; i++)
        data[i] = str.data[i];
    for (i = pos, j = pos + n; j < str.sizee; i++, j++)data[i] = str.data[j];
    return *this;
    std::string as;
    as.find_first_of("1232");
}

StringLib& StringLib::replace(const size_t& pos, const size_t& n, const StringLib& s) {
    StringLib str(data);
    unsigned i;
    str.erase(pos, n);
    str.insert(pos, s);
    sizee = str.sizee;
    delete[] data;
    data = new char[sizee];
    for (i = 0; i < sizee; i++)
        data[i] = str.data[i];
    return *this;
}

void StringLib::swap(StringLib& s) {
    char* str = new char[sizee];
    size_t i = this->copy(str, sizee - 1, 0);
    str[i] = 0;
    *this = s;
    s = str;
    delete[] str;
}

size_t StringLib::copy(char* cs, const size_t& n, const size_t& pos) const {
    size_t i, j;
    for (j = pos, i = 0; i < n; i++, j++)
        cs[i] = data[j];
    return i;
}


void StringLib::pop_back() {
    if(sizee>0){
        char* old_data = this->data;
        this->data = new char[sizee];
        for (size_t a = 0; a < sizee-1; a++) this->data[a] = old_data[a];
        data[sizee-1]='\0';
        this->sizee = sizee - 1;
        delete[] old_data;
    }
}


int StringLib::find_first_of(StringLib textForFind) {
    for (size_t a = 0; a < sizee; a++)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] == textForFind[aa]) return a;
    return 0;
}

int StringLib::find_last_of(StringLib textForFind) {
    for (size_t a = sizee-1; a >=0; a--)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] == textForFind[aa]) return a;
    return 0;
}


int StringLib::find_first_not_of(StringLib textForFind) {
    for (size_t a = 0; a < sizee; a++)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] != textForFind[aa]) return a;
    return 0;
}

int StringLib::find_last_not_of(StringLib textForFind) {
    for (size_t a = sizee - 1; a >= 0; a--)
        for (size_t aa = 0; aa < textForFind.sizee; aa++)
            if (data[a] != textForFind[aa]) return a;
    return 0;
}

