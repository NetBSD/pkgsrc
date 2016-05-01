$NetBSD: patch-src_misc.c,v 1.1 2016/05/01 19:56:40 dholland Exp $

- Use ctype.h functions correctly.

--- src/misc.c~	2004-11-10 17:21:46.000000000 +0000
+++ src/misc.c
@@ -85,7 +85,7 @@ char           *
 Str_skip_space(char *str)
 {
     if (str && *str) {
-	while (*str && isspace(*str))
+	while (*str && isspace((unsigned char)*str))
 	    str++;
     }
     return str;
@@ -102,7 +102,7 @@ Str_trim(char *str)
 	src = Str_skip_space(str);
 	n = strlen(src) - 1;
 
-	while (n > 0 && isspace(src[n]))
+	while (n > 0 && isspace((unsigned char)src[n]))
 	    n--;
 	src[n + 1] = '\0';
 
@@ -159,12 +159,12 @@ Str_escaped(char *str)
 	str[i++] = '\033';	/* destination */
 	len--;
 	p += n;
-	if (toupper(*p) == 'X') {
+	if (toupper((unsigned char)*p) == 'X') {
 	/* append carriage-return for `M-xcommand' */
 	    append = '\r';
 	    str[i++] = 'x';	/* destination */
 	    p++;
-	    while (isspace(*p)) {
+	    while (isspace((unsigned char)*p)) {
 		p++;
 		len--;
 	    }
@@ -214,7 +214,7 @@ Str_escaped(char *str)
 	    ch = *p;
 	    p++;
 	    len--;
-	    ch = toupper(ch);
+	    ch = toupper((unsigned char)ch);
 	    ch = (ch == '?' ? 127 : (ch - '@'));
 	}
 	str[i] = ch;
