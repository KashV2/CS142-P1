
// Buffer.h

#ifndef _Buffer_h_
#define _Buffer_h_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Format.h"

class Buffer
{
public:
    void display() const;
    const std::string& file_name() const { return file_name_; }
    void move_to_next_page();
    void move_to_previous_page();
    bool open(const std::string& file_name);
    void set_window_height(int h) { window_height_ = h; }
    void set_line_length(int h) { line_length_ = h; }
    void convert_text();

private:
    std::vector<std::string> v_lines_;
    std::vector<std::string> anchors_;
    std::vector<std::string> mod_lines_ = {}; // lines adjusted for line length
    int ix_top_line_ = 0;
    std::string file_name_;
    int window_height_;
    int line_length_; // self-explanatory
    Format file_;
};

inline void Buffer::move_to_next_page()
{
    ix_top_line_ += window_height_;
    if (ix_top_line_ >= mod_lines_.size())
        ix_top_line_ -= window_height_;
}

inline void Buffer::move_to_previous_page()
{
    ix_top_line_ -= window_height_;
    if (ix_top_line_ < 0)
        ix_top_line_ = 0;
}

#endif
