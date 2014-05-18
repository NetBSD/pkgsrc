$NetBSD: patch-inter.c,v 1.1 2014/05/18 21:24:56 joerg Exp $

--- inter.c.orig	2004-01-07 00:09:05.000000000 +0000
+++ inter.c
@@ -260,14 +260,14 @@ static char *generate_a_postpone_complet
 }
 /*}}}*/
 
-char **complete_help(char *text, int index)/*{{{*/
+char **complete_help(const char *text, int index)/*{{{*/
 {
   char **matches;
   matches = COMPLETION_MATCHES(text, generate_a_command_completion);
   return matches;
 }
 /*}}}*/
-char **default_completer(char *text, int index)/*{{{*/
+char **default_completer(const char *text, int index)/*{{{*/
 {
   if (cmds[index].synopsis) {
     fprintf(stderr, "\n%s %s\n", cmds[index].name, cmds[index].synopsis);
@@ -276,7 +276,7 @@ char **default_completer(char *text, int
   return NULL;
 }
 /*}}}*/
-char **complete_list(char *text, int index)/*{{{*/
+char **complete_list(const char *text, int index)/*{{{*/
 {
   char **matches;
   if (text[0] && isalpha(text[0])) {
@@ -288,12 +288,12 @@ char **complete_list(char *text, int ind
   }
 }
 /*}}}*/
-char **complete_priority(char *text, int index)/*{{{*/
+char **complete_priority(const char *text, int index)/*{{{*/
 {
   return complete_list(text, index);
 }
 /*}}}*/
-char **complete_postpone(char *text, int index)/*{{{*/
+char **complete_postpone(const char *text, int index)/*{{{*/
 {
   char **matches;
   want_postponed_entries = 0;
@@ -301,7 +301,7 @@ char **complete_postpone(char *text, int
   return matches;
 }
 /*}}}*/
-char **complete_open(char *text, int index)/*{{{*/
+char **complete_open(const char *text, int index)/*{{{*/
 {
   char **matches;
   want_postponed_entries = 1;
@@ -309,7 +309,7 @@ char **complete_open(char *text, int ind
   return matches;
 }
 /*}}}*/
-char **complete_done(char *text, int index)/*{{{*/
+char **complete_done(const char *text, int index)/*{{{*/
 {
   char **matches;
   matches = COMPLETION_MATCHES(text, generate_a_done_completion);
@@ -317,7 +317,7 @@ char **complete_done(char *text, int ind
 }
 /*}}}*/
 
-static char **tdl_completion(char *text, int start, int end)/*{{{*/
+static char **tdl_completion(const char *text, int start, int end)/*{{{*/
 {
   char **matches = NULL;
   if (start == 0) {
@@ -340,35 +340,35 @@ static char **tdl_completion(char *text,
   return matches;
 }
 /*}}}*/
-static char **null_tdl_completion(char *text, int start, int end)/*{{{*/
+static char **null_tdl_completion(const char *text, int start, int end)/*{{{*/
 {
   return NULL;
 }
 /*}}}*/
 #else
-char **complete_help(char *text, int index)/*{{{*/
+char **complete_help(const char *text, int index)/*{{{*/
 {
   return NULL;
 }/*}}}*/
-char **complete_list(char *text, int index)/*{{{*/
+char **complete_list(const char *text, int index)/*{{{*/
 {
   return NULL;
 }/*}}}*/
-char **complete_priority(char *text, int index)/*{{{*/
+char **complete_priority(const char *text, int index)/*{{{*/
 {
   return NULL;
 }/*}}}*/
-char **complete_postponed(char *text, int index)/*{{{*/
+char **complete_postponed(const char *text, int index)/*{{{*/
 {
   return NULL;
 }
 /*}}}*/
-char **complete_open(char *text, int index)/*{{{*/
+char **complete_open(const char *text, int index)/*{{{*/
 {
   return NULL;
 }
 /*}}}*/
-char **complete_done(char *text, int index)/*{{{*/
+char **complete_done(const char *text, int index)/*{{{*/
 {
   return NULL;
 }
@@ -556,7 +556,7 @@ static int setup_initval_hook(void)/*{{{
 static char *interactive_text_readline(char *prompt, char *initval, int *is_blank, int *error)/*{{{*/
 {
   char *line;
-  Function *old_rl_pre_input_hook = NULL;
+  rl_hook_func_t *old_rl_pre_input_hook = NULL;
   
   *error = 0;
   old_rl_pre_input_hook = rl_pre_input_hook;
@@ -633,9 +633,9 @@ char *interactive_text (char *prompt, ch
 #ifdef USE_READLINE
   if (isatty(0)) {
     char *result;
-    rl_attempted_completion_function = (CPPFunction *) null_tdl_completion;
+    rl_attempted_completion_function = null_tdl_completion;
     result = interactive_text_readline(prompt, initval, is_blank, error);
-    rl_attempted_completion_function = (CPPFunction *) tdl_completion;
+    rl_attempted_completion_function = tdl_completion;
     return result;
   } else {
     /* In case someone wants to drive tdl from a script, by redirecting stdin to it. */
@@ -653,7 +653,7 @@ void interactive(void)/*{{{*/
 #ifdef USE_READLINE
   if (isatty(0)) {
     rl_completion_entry_function = NULL;
-    rl_attempted_completion_function = (CPPFunction *) tdl_completion;
+    rl_attempted_completion_function = tdl_completion;
     interactive_readline();
   } else {
     /* In case someone wants to drive tdl from a script, by redirecting stdin to it. */
