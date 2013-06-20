$NetBSD: patch-support_htdigest.c,v 1.1 2013/06/20 09:06:45 taca Exp $

Fix for htpasswd: https://issues.apache.org/bugzilla/show_bug.cgi?id=54735

--- support/htdigest.c.orig	2010-08-20 13:16:24.000000000 +0000
+++ support/htdigest.c
@@ -96,12 +96,15 @@ static int get_line(char *s, int n, apr_
     char ch;
     apr_status_t rv = APR_EINVAL;
 
-    while (i < (n - 1) &&
+    /* we need 2 remaining bytes in buffer */
+    while (i < (n - 2) &&
            ((rv = apr_file_getc(&ch, f)) == APR_SUCCESS) && (ch != '\n')) {
         s[i++] = ch;
     }
+    /* First remaining byte potentially used here */
     if (ch == '\n')
         s[i++] = ch;
+    /* Second remaining byte used here */
     s[i] = '\0';
 
     if (rv != APR_SUCCESS)
@@ -202,8 +205,8 @@ int main(int argc, const char * const ar
 #if APR_CHARSET_EBCDIC
     rv = apr_xlate_open(&to_ascii, "ISO-8859-1", APR_DEFAULT_CHARSET, cntxt);
     if (rv) {
-        apr_file_printf(errfile, "apr_xlate_open(): %s (%d)\n",
-                apr_strerror(rv, line, sizeof(line)), rv);
+        apr_file_printf(errfile, "apr_xlate_open(): %pm (%d)\n",
+                &rv, rv);
         exit(1);
     }
 #endif
@@ -215,11 +218,8 @@ int main(int argc, const char * const ar
         rv = apr_file_open(&f, argv[2], APR_WRITE | APR_CREATE,
                            APR_OS_DEFAULT, cntxt);
         if (rv != APR_SUCCESS) {
-            char errmsg[120];
-
-            apr_file_printf(errfile, "Could not open passwd file %s for writing: %s\n",
-                    argv[2],
-                    apr_strerror(rv, errmsg, sizeof errmsg));
+            apr_file_printf(errfile, "Could not open passwd file %s for writing: %pm\n",
+                    argv[2], &rv);
             exit(1);
         }
         apr_cpystrn(user, argv[4], sizeof(user));
