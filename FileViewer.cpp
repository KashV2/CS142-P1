
// FileViewer.cpp

#include "FileViewer.h"

using namespace std;

void FileViewer::display()
{
    const string long_separator(50, '-');
    const string short_separator(8, '-');

    system(clear_command);

    if (!error_message_.empty()) {
        cout << "ERROR: " + error_message_ << endl;
        error_message_.clear();
    }

    string file_name = buffer_.file_name();
    if (file_name.empty())
        cout << "<no file opened>\n";
    else
        cout << file_name << endl;

    cout << long_separator << endl;
    buffer_.display();
    cout << long_separator << endl;
    cout << "  next  previous  open  quit go back\n";
    cout << short_separator << endl;
}

void read_f_names(vector<std::string>& f) {
    ifstream in;
    in.open("f_names.txt");
    string fname;
    f.push_back("");
    while (in) {
        in >> fname;
        f.push_back(fname);
    }

}

void FileViewer::execute_command(char command, bool& done)
{
    switch (command) {
    case 'n': {
        buffer_.move_to_next_page();
        break;
    }

    case 'o': {
        cout << "file name: ";
        string file_name;
        getline(cin, file_name);
        if (!buffer_.open(file_name))
            error_message_ = "Could not open " + file_name;
        else history_.push_back(file_name);
        break;
    }

    case 'p': {
        buffer_.move_to_previous_page();
        break;
    }

    case 'q': {
        done = true;
        break;
    }
    case 'g': {
        vector<std::string> f_names_;
        read_f_names(f_names_);

        //string link_num_str;
        int link_num;
        cout << "link number: ";
       // getline(cin, link_num_str);
       // int link_num = stoi(link_num_str);
        cin >> link_num;
        buffer_.open(f_names_[link_num]);
        history_.push_back(f_names_[link_num]);
        break;
    }

    case 'b' : {
        int size = history_.size();
        if (size - 2 < 0) error_message_ = "No previous file exists.";
        else {
            buffer_.open(history_[size - 2]);
            history_.pop_back();
        }
        break;
    }
    }
}




void FileViewer::run()
{
    cout << "Window height? ";
    cin >> window_height_;
    cin.get();  // '\n'
    cout << '\n';
    buffer_.set_window_height(window_height_);
    //
    cout << "Line length? ";
    cin >> line_length_;
    cin.get();  // '\n'
    cout << '\n';
    buffer_.set_line_length(line_length_);
    //


    bool done = false;
    while (!done) {
        display();

        cout << "command: ";
        char command;
        cin >> command;
        cin.get(); // '\n'

        execute_command(command, done);

        cout << endl;
    }
}
