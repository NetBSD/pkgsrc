$NetBSD: patch-lswt.c,v 1.1 2026/04/15 08:41:19 kikadf Exp $

* Fix ctype

--- lswt.c.orig	2026-04-06 08:40:47.751853736 +0000
+++ lswt.c
@@ -610,7 +610,7 @@ static const struct zwlr_foreign_topleve
 static bool string_needs_quotes (char *str)
 {
 	for (; *str != '\0'; str++)
-		if ( isspace(*str) || *str == '"' || *str == '\'' || !isascii(*str) )
+		if ( isspace((unsigned char)*str) || *str == '"' || *str == '\'' || !isascii((unsigned char)*str) )
 			return true;
 	return false;
 }
@@ -766,7 +766,7 @@ static size_t real_strlen (const char *s
 				break;
 
 			default:
-				if (isspace(*str))
+				if (isspace((unsigned char)*str))
 					has_space = true;
 				i++;
 				break;
