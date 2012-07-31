$NetBSD: patch-Source_WebCore_css_CSSGrammar.y,v 1.1 2012/07/31 13:59:55 prlw1 Exp $

Fix for Bug 92264: Build fix with newer bison 2.6.
https://bugs.webkit.org/show_bug.cgi?id=92264

--- Source/WebCore/css/CSSGrammar.y.orig	2012-04-24 01:35:25.000000000 +0000
+++ Source/WebCore/css/CSSGrammar.y
@@ -53,14 +53,13 @@ using namespace HTMLNames;
 #define YYMAXDEPTH 10000
 #define YYDEBUG 0
 
-// FIXME: Replace with %parse-param { CSSParser* parser } once we can depend on bison 2.x
-#define YYPARSE_PARAM parser
-#define YYLEX_PARAM parser
-
 %}
 
 %pure_parser
 
+%parse-param { CSSParser* parser }
+%lex-param { CSSParser* parser }
+
 %union {
     bool boolean;
     char character;
@@ -88,7 +87,7 @@ using namespace HTMLNames;
 
 %{
 
-static inline int cssyyerror(const char*)
+static inline int cssyyerror(void*, const char*)
 {
     return 1;
 }
