
//FileReader.h

#ifndef _Format_h_
#define _Format_h_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class Format {
public:
	Format() : mod_lines_({}) {}
	void record_f(const std::string& s);
	const std::vector<std::string> &lines() { return (mod_lines_); }
	const std::vector<std::string> &anchors() { return (anchors_); }
	void anchor_log();
	void format_lines(const std::vector<std::string>& s, int length);

private:
	std::vector<std::string> mod_lines_;
	std::vector<std::string> anchors_;

};

#endif
