//FileReader.cpp

#include <sstream>

#include "Format.h"
using namespace std;

/*void FileReader::read_lines(int length) {
    string line;
    vector<string> lines;
    while (getline(in, line))
        lines.push_back(line);

    string word;
    vector<string> words;

    for (int i = 0; i < lines.size(); i++) {
        istringstream ss(lines[i]);
        while (ss >> word) {
            if (word == "<a") {
                string f_name;
                ss >> f_name;
                ss >> word;

                string anchor = word;

                ifstream in_f("f_names.txt");
                string file_name;
                bool f_repeat = false;
                while (getline(in_f, file_name)) {
                    if (file_name == f_name) { f_repeat = true; }
                }
                in_f.close();

                ofstream out_f("f_names.txt", ios::app);
                if (!f_repeat) { out_f << f_name << endl; }
                out_f.close();

                if (anchors_.size() == 0) anchors_.push_back(word);
                else {
                    bool repeat = false;
                    for (string i : anchors_) {
                        if (word == i) repeat = true;
                    }
                    if (!repeat) anchors_.push_back(word);
                }

                auto itr = find(anchors_.begin(), anchors_.end(), anchor);
                int index = distance(anchors_.begin(), itr) + 1;
                string anchor_display = "<" + word + "[" + to_string(index) + "]";
                words.push_back(anchor_display);
            }

            else words.push_back(word);
        }
    }
    string test;
    for (int i = 0; i < words.size(); i++) {

        if (words[i] == "<br>") {
            mod_lines_.push_back(test);
            test.clear();
        }

        else if (words[i] == "<p>") {
            mod_lines_.push_back(test);
            mod_lines_.push_back("");
            test.clear();
        }

        else {
            if (words[i].size() >= length) mod_lines_.push_back(words[i]);
            else if (test.size() + words[i].size() <= (length)) {
                test += words[i] + " ";
            }
            else {
                mod_lines_.push_back(test);
                test.clear();
                test += words[i] + " ";
            }
            if ((i + 1) == words.size()) mod_lines_.push_back(words[i]);
        }
    }


}*/

/*void FileReader::record_f(const std::string& s) {
    ifstream in_f("f_names.txt");
    string file_name;
    bool f_repeat = false;
    while (getline(in_f, file_name)) {
        if (file_name == s) { f_repeat = true; }
    }
    in_f.close();

    ofstream out_f("f_names.txt", ios::app);
    if (!f_repeat) { 
        out_f << s << endl;
        anchors_.push_back(s);
    }
    out_f.close();
}*/

void Format::record_f(const std::string& s) {
    anchors_.clear();
    ifstream in_f("f_names.txt");
    string file_name;
    bool f_repeat = false;
    while (getline(in_f, file_name)) {
        if (file_name == s) { f_repeat = true; }
        anchors_.push_back(file_name);
    }
    in_f.close();

    ofstream out_f("f_names.txt", ios::app);
    if (!f_repeat) {
        out_f << s << endl;
        anchors_.push_back(s);
    }
    out_f.close();
}

void Format::anchor_log() {
    ifstream in_f("f_names.txt");
    string anchor;

    while (getline(in_f, anchor))
        anchors_.push_back(anchor);
    in_f.close();
}

void Format::format_lines(const std::vector<std::string>& s, int length) {
    mod_lines_.clear();
    string test;
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == "<br>") {
            mod_lines_.push_back(test);
            test.clear();
        }

        else if (s[i] == "<p>") {
            mod_lines_.push_back(test);
            mod_lines_.push_back("");
            test.clear();
        }

        else {
            if (s[i].size() >= length) mod_lines_.push_back(s[i]);
            else if (test.size() + s[i].size() <= (length)) {
                test += s[i] + " ";
            }
            else {
                mod_lines_.push_back(test);
                test.clear();
                test += s[i] + " ";
            }
            if ((i + 1) == s.size()) mod_lines_.push_back(s[i]);
        }
    }
}

/*std::string anchor_display(const std::vector<std::string>& anchor, const string& f_name, const string& text) {
   
    auto itr = find(anchor.begin(), anchor.end(), f_name);
    int index = distance(anchor.begin(), itr) + 1;
    string anchor_display = "<" + text + "[" + to_string(index) + "]";
    return (anchor_display);
}*/
