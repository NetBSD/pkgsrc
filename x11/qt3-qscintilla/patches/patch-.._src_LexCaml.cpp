$NetBSD: patch-.._src_LexCaml.cpp,v 1.1 2012/01/24 08:18:41 sbd Exp $

--- ../src/LexCaml.cpp.orig	2005-08-08 20:12:16.000000000 +0000
+++ ../src/LexCaml.cpp
@@ -275,7 +275,7 @@ void ColouriseCamlDoc(
 			// [try to] interpret as [additional] operator char
 			char* o = 0;
 			if (iscaml(ch) || isspace(ch)			/* ident or whitespace */
-				|| ((o = strchr(")]};,\'\"`#", ch)) != 0)/* "termination" chars */
+				|| ((o = (char*)strchr(")]};,\'\"`#", ch)) != 0)/* "termination" chars */
 				|| !strchr("!$%&*+-./:<=>?@^|~", ch)/* "operator" chars */) {
 				// check for INCLUSIVE termination
 				if (o && strchr(")]};,", ch)) {
