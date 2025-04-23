//
// Created by kevin on 4/23/2025.
//

#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File {
public:
    void set_name(const string &name);

    void set_content(const string &content);

    [[nodiscard]] string get_name() const;

    [[nodiscard]] string get_content() const;

    File(const string &name, const string &content);

private:
    string name;
    string content;

};


#endif //FILE_H
