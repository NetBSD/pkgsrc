$NetBSD: patch-lib_tests_test__wordtokenizer__main.cpp,v 1.1 2020/04/19 01:17:11 joerg Exp $

operator<< must be defined before call site.

--- lib/tests/test_wordtokenizer_main.cpp.orig	2020-04-18 23:43:49.550865959 +0000
+++ lib/tests/test_wordtokenizer_main.cpp
@@ -6,13 +6,14 @@
 
 #include "asserttestexit.h"
 #include "srchilite/wordtokenizer.h"
+
+static std::ostream &operator <<(std::ostream &os, const srchilite::WordTokenizer::WordTokenizerResults::value_type &);
+
 #include "srchilite/tostringcollection.h"
 
 using namespace std;
 using namespace srchilite;
 
-static ostream &operator <<(ostream &os, const WordTokenizer::WordTokenizerResults::value_type &);
-
 ostream &operator <<(ostream &os, const WordTokenizer::WordTokenizerResults::value_type &token) {
     if (token.first.size()) {
         os << "space: \"" << token.first << "\"" << endl;
