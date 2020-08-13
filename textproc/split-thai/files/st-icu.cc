/*
 *   split up thai strings in a file, stdin or args into "words"
 */
#include <fstream>
#include <vector>

#include <unicode/brkiter.h>
#include <unicode/regex.h>
#include <unicode/ucnv.h>
#include <unicode/ustream.h>
#include <unicode/ustdio.h>

using namespace std;
using namespace icu;

void usage() {
 const char *progname = "st-icu";
	
 cout << endl <<
  "Usage: " << progname << " [stdin|filename|thaiarg1 thaiarg2 ...]" <<
    endl << endl <<
     "This program attempts to split thai strings into thai words." << endl <<
     "It takes a filename, stdin, or UTF8 thai string(s) as arguments" << endl <<
     "and prints out the string separated by spaces." << endl <<
     "When no argument is given, it can read lines from stdin, and" << endl <<
     "separate thai words in the line by spaces." << endl << endl <<
     "returns 0 on succes, or non-zero otherwise" << endl << endl;
}

// return true if string contains any thai unicode
bool contains_thai(const UnicodeString &s) {
	UErrorCode status = U_ZERO_ERROR;
	// matches one or more thai chars, \u0e01-\u0e5b should work too
	RegexMatcher *matcher = new RegexMatcher("[\u0e00-\u0e7f]+", 0, status);

	if (U_FAILURE(status)) {
		// syntax errors in the regular expression
		cerr << "error creating RegexMatcher" << endl;
		exit(1);
	}

	matcher->reset(s);
	if (matcher->find())
		return true;
	else
		return false;
}

// split a unicode string by word boundaries.  if arg contains
// whitespaces, it will get consolidated to single spaces.
// if string has no thai characters, return it unmodified
UnicodeString split_words_consolidated(const UnicodeString &s) {
	if ( ! contains_thai(s) ) {
		return s;
	}
	
	UErrorCode status = U_ZERO_ERROR;
	BreakIterator* wordBreaker =
		BreakIterator::createWordInstance(Locale::getUS(), status);
	if ( U_FAILURE(status) ) {
		cerr << "error creating BreakIterator" << endl;
		exit(1);
	}

	wordBreaker->setText(s);	
	vector<int32_t> vbreak;

	int32_t pos = wordBreaker->first();
	while( pos != BreakIterator::DONE ) {
		// cout << "boundary " << pos << endl;
		vbreak.push_back(pos);
		pos = wordBreaker->next();
	}

	// only one word found, trim and done
	if ( vbreak.size() == 1 ) {
		UnicodeString ss(s);
		return ss.trim();
	}
	
	UnicodeString rs;
	for (int i = 0 ; i < vbreak.size() - 1; i++) {
		UnicodeString ss;
		s.extractBetween(vbreak[i], vbreak[i+1], ss);
		ss.trim();
		if ( ss != "" )
			rs += ss + " ";
	}

	return rs.trim();
}

// split a unicode string by word boundaries trying to preserve
// original spacing
UnicodeString split_words(const UnicodeString &s) {
	UnicodeString tempStr;
	UnicodeString rs;
	for (int i = 0 ; i < s.length() ; i++) {
		if ( ! u_isUWhiteSpace(s[i]) ) {
			tempStr += s[i];
		} else {
			if ( tempStr.length() > 0 ) {
				rs += split_words_consolidated(tempStr);
				tempStr.remove();
			}
			rs += s[i];
		}
	}
	if ( tempStr.length() > 0 )
		rs += split_words_consolidated(tempStr);
	return rs;
}

// split stdin
void split_stdin() {
	UFILE *in = u_finit(stdin, NULL, NULL);
	if ( !in ) {
		cerr << "error: u_finit of stdin failed" << endl;
		exit(1);
	}

	UChar uch;
	UnicodeString line;
	while ( (uch = u_fgetc(in)) ) {
		if ( uch == 0xffff ) {
			break;
		} else if ( uch == '\n' ) {
			UnicodeString s(line);
			cout << split_words(s) << endl;
			line = "";
		} else {
			line += uch;
		}
	}
		
	u_fclose(in);
}

// read file line by line, spliting each line 1 at a time
void split_file(const char* filename) {
	UFILE *in = u_fopen(filename, "r", NULL, NULL);
	if ( !in ) {
		cerr << "error: opening file " << filename << endl;
		exit(1);
	}
	const int32_t maxLine = 1024;
	UChar line[maxLine];
	while ( u_fgets(line, maxLine, in) != NULL ) {
		//cout << split_words(line) << endl;
		cout << split_words(line);
	}

	u_fclose(in);
}

// check if file is "readable"
bool is_readable(const char* fname) {
    ifstream infile(fname);
    return infile.good();
}

int main(int argc, char **argv) {
 	// utf8 for everything
	ucnv_setDefaultName("UTF-8");

	// read stdin when no args passed in
	if ( argc <= 1 ) {
		split_stdin();
		exit(0);
	}

	// check second arg for help flag
	UnicodeString arg2(argv[1]);
	if ( arg2 == "-h" || arg2 == "-H" || arg2 == "-?" || arg2 == "-help" ) {
		usage();
		exit(0);
	}

	// if only one arg and exists with arg name, process file
	if ( argc == 2 && is_readable(argv[1]) ) {
		split_file(argv[1]);
		exit(0);
	}

	// join remainder of args and process as string
	UnicodeString inArgs;
	for ( int i = 1 ; i < argc ; i++ ) {
		UnicodeString s(argv[i]);
		inArgs += s;
		if ( i < (argc - 1) )
			inArgs += " ";
	}
	cout << split_words(inArgs) << endl;
	exit(0);
}
