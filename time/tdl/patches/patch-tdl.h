$NetBSD: patch-tdl.h,v 1.1 2014/05/18 21:24:56 joerg Exp $

--- tdl.h.orig	2004-01-07 00:09:05.000000000 +0000
+++ tdl.h
@@ -82,7 +82,7 @@ struct command {/*{{{*/
   int (*func)(char **); /* ptr to function that actually does the work for this cmd */
   char *descrip; /* One line description */
   char *synopsis; /* Description of parameters */
-  char ** (*completer)(char *, int); /* Function to generate completions */
+  char ** (*completer)(const char *, int); /* Function to generate completions */
   unsigned char  dirty; /* 1 if operation can dirty the database, 0 if it leaves it clean */
   unsigned char  load_db; /* 1 if cmd requires current database to be loaded first */
   unsigned char  matchlen; /* number of characters to make command unambiguous */
@@ -170,12 +170,12 @@ void load_database_if_not_loaded(void);
 /* In inter.c */
 void interactive(void);
 char *interactive_text(char *prompt, char *initval, int *is_blank, int *error);
-char **complete_help(char *, int);
-char **complete_list(char *, int);
-char **complete_priority(char *, int);
-char **complete_postpone(char *, int);
-char **complete_open(char *, int);
-char **complete_done(char *, int);
+char **complete_help(const char *, int);
+char **complete_list(const char *, int);
+char **complete_priority(const char *, int);
+char **complete_postpone(const char *, int);
+char **complete_open(const char *, int);
+char **complete_done(const char *, int);
 
 /* In narrow.c */
 struct node *get_narrow_top(void);
