//
// Created by kevin on 4/23/2025.
//

#include "File.h"

void File::set_name(const string &name) {
    this->name = name;
}

void File::set_content(const string &content) {
    this->content = content;
}

[[nodiscard]] string File::get_name() const {
    return name;
}

[[nodiscard]] string File::get_content() const {
    return content;
}

File::File(const string &name, const string &content)
    : name(name),
      content(content) {
}
