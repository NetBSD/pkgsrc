$NetBSD: patch-src_config.c,v 1.1 2020/11/19 11:03:04 nia Exp $

Arguments to ctype functions must be unsigned char.

--- src/config.c.orig	2020-10-24 08:44:12.000000000 +0000
+++ src/config.c
@@ -33,7 +33,7 @@ bool parse_long(const char *s, long *des
 		log_error("Invalid number: %s", s);
 		return false;
 	}
-	while (isspace(*endptr))
+	while (isspace((unsigned char)*endptr))
 		++endptr;
 	if (*endptr) {
 		log_error("Trailing characters: %s", s);
@@ -74,7 +74,7 @@ const char *parse_readnum(const char *sr
 		log_error("No number found: %s", src);
 		return src;
 	}
-	while (*pc && (isspace(*pc) || *pc == ',')) {
+	while (*pc && (isspace((unsigned char)*pc) || *pc == ',')) {
 		++pc;
 	}
 	*dest = val;
@@ -154,7 +154,7 @@ conv *parse_blur_kern(const char *src, c
 
 	// Detect trailing characters
 	for (; *pc && *pc != ';'; pc++) {
-		if (!isspace(*pc) && *pc != ',') {
+		if (!isspace((unsigned char)*pc) && *pc != ',') {
 			// TODO isspace is locale aware, be careful
 			log_error("Trailing characters in blur kernel string.");
 			goto err2;
@@ -164,7 +164,7 @@ conv *parse_blur_kern(const char *src, c
 	// Jump over spaces after ';'
 	if (*pc == ';') {
 		pc++;
-		while (*pc && isspace(*pc)) {
+		while (*pc && isspace((unsigned char)*pc)) {
 			++pc;
 		}
 	}
@@ -418,7 +418,7 @@ bool parse_rule_opacity(c2_lptr_t **res,
 	}
 
 	// Skip over spaces
-	while (*endptr && isspace(*endptr))
+	while (*endptr && isspace((unsigned char)*endptr))
 		++endptr;
 	if (':' != *endptr) {
 		log_error("Opacity terminator not found: %s", src);
