$NetBSD: patch-extras_htpasswd.c,v 1.1 2026/09/25 14:20:40 wiz Exp $

Not a CVE, two things in the htpasswd utility.

The line buffers are MAX_STRING_LEN (256) while a .htpasswd line is
"user:hash".  The hash of a modern crypt(3) runs to about a hundred
characters, so a line written by any other tool does not fit, and
my_getline() truncates at the limit without saying so; the remainder is
then read as the next line.  Reading an existing file in order to add a
user to it therefore corrupted it.  FreeBSD ports, Debian and Fedora all
enlarge these buffers.

fgets() is not checked when the password comes in on stdin, so pass is
left uninitialised if it fails, and a leading NUL byte leaves strlen()
at 0; either way pass[strlen(pass)-1] reads before the buffer.  Both
paths fire under AddressSanitizer on the routine extracted unchanged
from 2.29 (empty stdin, and a line starting with a NUL byte).  No other
packaging fixes this one.

--- extras/htpasswd.c.orig
+++ extras/htpasswd.c
@@ -20,6 +20,12 @@
 #define CR 13
 
 #define MAX_STRING_LEN 256
+/* A .htpasswd line is "user:hash".  The hash of a modern crypt(3) is around a
+** hundred characters, so a line does not fit in MAX_STRING_LEN.  my_getline()
+** truncates silently at its limit and the remainder is then read as the next
+** line, so reading an existing file to update it corrupted it.
+*/
+#define MAX_LINE_LEN (MAX_STRING_LEN + 1 + 256)
 
 int tfd;
 char temp_template[] = "/tmp/htp.XXXXXX";
@@ -112,8 +118,13 @@
 
     if ( ! isatty( fileno( stdin ) ) )
 	{
-	(void) fgets( pass, sizeof(pass), stdin );
-	if ( pass[strlen(pass) - 1] == '\n' )
+	/* fgets() can fail, leaving pass uninitialised, and a NUL byte on
+	** stdin leaves strlen() at 0; either way pass[strlen(pass)-1] would
+	** read before the buffer.
+	*/
+	if ( fgets( pass, sizeof(pass), stdin ) == (char*) 0 )
+	    pass[0] = '\0';
+	if ( pass[0] != '\0' && pass[strlen(pass) - 1] == '\n' )
 	    pass[strlen(pass) - 1] = '\0';
 	pw = pass;
 	}
@@ -149,8 +160,8 @@
 int main(int argc, char *argv[]) {
     FILE *tfp,*f;
     char user[MAX_STRING_LEN];
-    char line[MAX_STRING_LEN];
-    char l[MAX_STRING_LEN];
+    char line[MAX_LINE_LEN];
+    char l[MAX_LINE_LEN];
     char w[MAX_STRING_LEN];
     char command[MAX_STRING_LEN];
     int found;
@@ -188,7 +199,7 @@
     user[sizeof(user)-1] = '\0';
 
     found = 0;
-    while(!(my_getline(line,MAX_STRING_LEN,f))) {
+    while(!(my_getline(line,MAX_LINE_LEN,f))) {
         if(found || (line[0] == '#') || (!line[0])) {
             putline(tfp,line);
             continue;
