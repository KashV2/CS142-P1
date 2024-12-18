// Buffer.cpp

#include "Buffer.h"

using namespace std;

void Buffer::display() const
{
    int ix_stop_line_ = ix_top_line_ + window_height_;
    //
    for (int i = ix_top_line_; i < ix_stop_line_; ++i) {
        if (i < mod_lines_.size())
            cout << std::setw(6) << i + 1 << "  " << mod_lines_[i];
        cout << '\n';
    }//
}

bool Buffer::open(const string& new_file_name)
{
   std::ifstream file(new_file_name);
    if (!file)
        return false;

    /*FileReader file_(new_file_name);
    if (file_.open())
        return false;*/

    v_lines_.clear();
    mod_lines_.clear();
    file_.anchor_log();
    // Note: the vector is cleared only after we know the file
    // opened successfully.

    string line;
    while (getline(file, line))
        v_lines_.push_back(line);
    convert_text();

    anchors_ = file_.anchors();
    mod_lines_ = file_.lines();

    file_name_ = new_file_name;
    ix_top_line_ = 0;
    return true;
}

void Buffer::convert_text() {
    string word, f_name, text;
    vector<string> words;

    for (int i = 0; i < v_lines_.size(); i++) {
        istringstream ss(v_lines_[i]);
        while (ss >> word) {
            if (word == "<a") {
                ss >> f_name;
                file_.record_f(f_name);
                anchors_ = file_.anchors();

                ss >> text;
                auto itr = find(anchors_.begin(), anchors_.end(), f_name);
                int index = distance(anchors_.begin(), itr) + 1;
                string anchor_display = "<" + text + "[" + to_string(index) + "]";
                words.push_back(anchor_display);
            }

            else words.push_back(word);
        }
    }

    file_.format_lines(words, line_length_);
}
