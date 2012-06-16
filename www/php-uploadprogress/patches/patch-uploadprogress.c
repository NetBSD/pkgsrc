$NetBSD: patch-uploadprogress.c,v 1.1 2012/06/16 03:09:19 taca Exp $

* Use modern data structure name.
* Add support for PHP 5.4.x.

--- uploadprogress.c.orig	1970-01-01 09:13:08.000000000 +0000
+++ uploadprogress.c
@@ -32,7 +32,7 @@
 #endif
 
 /* {{{ uploadprogress_functions[] */
-function_entry uploadprogress_functions[] = {
+zend_function_entry uploadprogress_functions[] = {
     PHP_FE(uploadprogress_get_info, NULL)
     PHP_FE(uploadprogress_get_contents, NULL)
     { NULL, NULL, NULL }
@@ -457,11 +457,12 @@ static void uploadprogress_file_php_get_
         /* uses mmap if possible */
         if ((len = php_stream_copy_to_mem(stream, &contents, maxlen, 0)) > 0) {
 
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
             if (PG(magic_quotes_runtime)) {
                 contents = php_addslashes(contents, len, &newlen, 1 TSRMLS_CC);
                 len = newlen;
             }
-
+#endif
             RETVAL_STRINGL(contents, len, 0);
         } else if (len == 0) {
             RETVAL_EMPTY_STRING();
