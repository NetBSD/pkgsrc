$NetBSD: patch-cfg__param.c,v 1.3 2017/02/06 14:14:48 adam Exp $

Fix compilation.

--- cfg_param.c.orig	2015-08-27 09:01:51.000000000 +0000
+++ cfg_param.c
@@ -699,14 +699,12 @@ int fread_line(FILE * f_conf, char *line
 struct ci_conf_entry *find_action(char *str, char **arg)
 {
      char *end, *table, *s;
-     int size;
      end = str;
-     while (*end != '\0' && !isspace(*end))
+     while (*end != '\0' && !isspace((unsigned char)*end))
           end++;
-     size = end - str;
      *end = '\0';               /*Mark the end of Variable...... */
      end++;                     /*... and continue.... */
-     while (*end != '\0' && isspace(*end))      /*Find the start of arguments ...... */
+     while (*end != '\0' && isspace((unsigned char)*end))      /*Find the start of arguments ...... */
           end++;
      *arg = end;
      if ((s = strchr(str, '.')) != NULL) {
@@ -744,7 +742,7 @@ char **split_args(char *args)
           else {
               /*Support arguments in the form arg{a, b...}*/
               brkt = 0;
-              while (*end != '\0' && (!isspace(*end) || brkt)) {
+              while (*end != '\0' && (!isspace((unsigned char)*end) || brkt)) {
                     if (*end == '{') brkt = 1;
                     else if (brkt && *end == '}') brkt = 0;
                     end++;
@@ -763,7 +761,7 @@ char **split_args(char *args)
 
           if (*end == '"')
                end++;
-          while (*end != '\0' && isspace(*end))
+          while (*end != '\0' && isspace((unsigned char)*end))
                end++;
 
      } while (*end != '\0');
@@ -795,7 +793,7 @@ int process_line(char *orig_line)
      line[LINESIZE-1] = '\0';
 
      str = line;
-     while (*str != '\0' && isspace(*str))      /*Eat the spaces in the begging */
+     while (*str != '\0' && isspace((unsigned char)*str))      /*Eat the spaces in the begging */
           str++;
      if (*str == '\0' || *str == '#')   /*Empty line or comment */
           return 1;
