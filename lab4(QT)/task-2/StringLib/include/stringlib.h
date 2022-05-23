#ifndef STRINGLIB_H
#define STRINGLIB_H

#include "StringLib_global.h"
#include "function.h"

class STRINGLIB_EXPORT StringLib
{
private:
    char* data;
    size_t sizee;
public:
    StringLib();

    StringLib(const StringLib& s);

    StringLib(const char* cs);

    StringLib(const StringLib& s, const size_t& pos, const size_t& n);

    StringLib(const char* cs, const size_t& n);

    StringLib(const size_t& n, const char& c);

    ~StringLib();

    char* getText();

    void setText(char* text);

    size_t getLength() const;

    void setLength(size_t sizee);

    void add(const StringLib& text);

    char at(size_t pos) const;

    char back() const;

    char front() const;

    bool compare(const StringLib& string) const;

    char operator[](size_t pos);

    void append(StringLib& string);

    bool empty();

    void clear();

    void push_back(char q);

    void pop_back();

    size_t capacity();

    size_t size();

    size_t lenght();

    void resize(size_t sizee, char c);

    size_t max_size();

    StringLib& assign(const char* cs, const size_t& n);

    StringLib& insert(const size_t& pos, const StringLib& s);

    StringLib& erase(const size_t& pos, const size_t& n);

    StringLib& replace(const size_t& pos, const size_t& n, const StringLib& s);

    size_t copy(char* cs, const size_t& n, const size_t& pos) const;

    void swap(StringLib& s);

    size_t rfind(const char* s2);

    int find(StringLib textForFind);

    int find_first_of(StringLib textForFind);

    int find_last_of(StringLib textForFind);

    int find_first_not_of(StringLib textForFind);

    int find_last_not_of(StringLib textForFind);
};

StringLib operator+(const StringLib& string1, const StringLib& string2);
bool operator==(const StringLib& string1, const StringLib& string2);


#endif // STRINGLIB_H
