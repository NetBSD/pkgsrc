$NetBSD: patch-src_c2.c,v 1.1 2020/11/19 11:03:04 nia Exp $

Arguments to ctype functions must be unsigned char.

--- src/c2.c.orig	2020-10-24 08:44:12.000000000 +0000
+++ src/c2.c
@@ -240,7 +240,7 @@ static inline int strcmp_wd(const char *
 		return ret;
 
 	char c = src[strlen(needle)];
-	if (isalnum(c) || '_' == c)
+	if (isalnum((unsigned char)c) || '_' == c)
 		return 1;
 	else
 		return 0;
@@ -386,7 +386,7 @@ c2_lptr_t *c2_parse(c2_lptr_t **pcondlst
 // TODO Not a very good macro
 #define C2H_SKIP_SPACES()                                                                \
 	{                                                                                \
-		while (isspace(pattern[offset]))                                         \
+		while (isspace((unsigned char)pattern[offset]))                          \
 			++offset;                                                        \
 	}
 
@@ -430,7 +430,7 @@ static int c2_parse_grp(const char *patt
 		assert(elei <= 2);
 
 		// Jump over spaces
-		if (isspace(pattern[offset]))
+		if (isspace((unsigned char)pattern[offset]))
 			continue;
 
 		// Handle end of group
@@ -578,7 +578,7 @@ static int c2_parse_target(const char *p
 
 	// Copy target name out
 	int tgtlen = 0;
-	for (; pattern[offset] && (isalnum(pattern[offset]) || '_' == pattern[offset]);
+	for (; pattern[offset] && (isalnum((unsigned char)pattern[offset]) || '_' == pattern[offset]);
 	     ++offset) {
 		++tgtlen;
 	}
@@ -825,7 +825,7 @@ static int c2_parse_pattern(const char *
 		pleaf->ptntype = C2_L_PTINT;
 		offset = to_int_checked(endptr - pattern);
 		// Make sure we are stopping at the end of a word
-		if (isalnum(pattern[offset])) {
+		if (isalnum((unsigned char)pattern[offset])) {
 			c2_error("Trailing characters after a numeric pattern.");
 		}
 	} else {
@@ -834,7 +834,7 @@ static int c2_parse_pattern(const char *
 		char delim = '\0';
 
 		// String flags
-		if (tolower(pattern[offset]) == 'r') {
+		if (tolower((unsigned char)pattern[offset]) == 'r') {
 			raw = true;
 			++offset;
 			C2H_SKIP_SPACES();
@@ -1033,7 +1033,7 @@ static bool c2_l_postprocess(session_t *
 	// Warn about lower case characters in target name
 	if (pleaf->predef == C2_L_PUNDEFINED) {
 		for (const char *pc = pleaf->tgt; *pc; ++pc) {
-			if (islower(*pc)) {
+			if (islower((unsigned char)*pc)) {
 				log_warn("Lowercase character in target name \"%s\".",
 				         pleaf->tgt);
 				break;
