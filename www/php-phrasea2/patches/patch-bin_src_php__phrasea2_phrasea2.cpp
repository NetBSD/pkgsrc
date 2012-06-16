$NetBSD: patch-bin_src_php__phrasea2_phrasea2.cpp,v 1.1 2012/06/16 03:07:54 taca Exp $

Use modern data structure name.

--- phrasea2.cpp.orig	2011-01-27 17:41:59.000000000 +0000
+++ phrasea2.cpp
@@ -46,7 +46,7 @@ ZEND_DECLARE_MODULE_GLOBALS(phrasea2)
 
 // -----------------------------------------------------------------------------
 // option -Wno-write-strings to gcc prevents warnings on this section
-static function_entry phrasea2_functions[] = {
+static zend_function_entry phrasea2_functions[] = {
 	PHP_FE(phrasea_info, NULL) 
 	PHP_FE(phrasea_conn, NULL)
 	PHP_FE(phrasea_create_session, NULL) 
