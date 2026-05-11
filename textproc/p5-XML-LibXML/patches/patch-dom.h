$NetBSD: patch-dom.h,v 1.1 2026/05/11 17:39:13 wiz Exp $

fix: validate UTF-8 continuation bytes in domParseChar
https://github.com/cpan-authors/XML-LibXML/pull/149

--- dom.h.orig	2016-05-30 09:01:59.000000000 +0000
+++ dom.h
@@ -58,7 +58,7 @@ domReconcileNs(xmlNodePtr tree);
  * NAME domParseChar
  * TYPE function
  * SYNOPSIS
- *   int utf8char = domParseChar( curchar, &len );
+ *   int utf8char = domParseChar( curchar, &len, remaining );
  *
  * The current char value, if using UTF-8 this may actually span
  * multiple bytes in the given string. This function parses an utf8
@@ -79,12 +79,14 @@ domReconcileNs(xmlNodePtr tree);
  *
  * Returns the current char value and its length
  *
- * NOTE: If the character passed to this function is not a UTF
- * character, the return value will be 0 and the length of the
- * character is -1!
+ * NOTE: If the character passed to this function is not a valid UTF-8
+ * character (truncated sequence, invalid continuation byte, or
+ * codepoint not allowed by IS_CHAR), the return value will be 0 and
+ * the length will be set to 1 so callers can safely advance past the
+ * bad byte.
  */
 int
-domParseChar( xmlChar *characters, int *len );
+domParseChar( xmlChar *characters, int *len, int remaining );
 
 xmlNodePtr
 domReadWellBalancedString( xmlDocPtr doc, xmlChar* string, int repair );
