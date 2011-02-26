$NetBSD: patch-grapheme_grapheme__string.c,v 1.1 2011/02/26 02:55:28 taca Exp $

A fix for CVE-2011-0420 (CERT: VU#210829) from PHP's repository, r306449.

--- grapheme/grapheme_string.c.orig	1970-01-01 09:13:08.000000000 +0000
+++ grapheme/grapheme_string.c
@@ -819,11 +819,17 @@ PHP_FUNCTION(grapheme_extract)
 	}
 
 	if ( lstart > INT32_MAX || lstart < 0 || lstart >= str_len ) {
+		intl_error_set( NULL, U_ILLEGAL_ARGUMENT_ERROR, "grapheme_extract: start not contained in string", 0 TSRMLS_CC );
 
-		intl_error_set( NULL, U_ILLEGAL_ARGUMENT_ERROR, "grapheme_extract: start not contained in string", 1 TSRMLS_CC );
-
 		RETURN_FALSE;
 	}
+	if ( size > INT32_MAX || size < 0) {
+		intl_error_set( NULL, U_ILLEGAL_ARGUMENT_ERROR, "grapheme_extract: size is invalid", 0 TSRMLS_CC );
+		RETURN_FALSE;
+	}
+	if (size == 0) {
+		RETURN_EMPTY_STRING();
+	}
 
 	/* we checked that it will fit: */
 	start = (int32_t) lstart;
