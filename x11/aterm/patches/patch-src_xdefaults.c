$NetBSD: patch-src_xdefaults.c,v 1.1 2016/05/01 19:56:40 dholland Exp $

- Pass the right type (int) for %*s formats.
- Use ctype.h functions correctly.

--- src/xdefaults.c~	2005-06-03 20:11:55.000000000 +0000
+++ src/xdefaults.c
@@ -516,7 +516,7 @@ usage(int type)
 		fprintf(stderr, "    %s%s %-*s%s%s\n",
 			(optList_isBool(i) ? "-/+" : "-"),
 			optList[i].opt,
-			(INDENT - strlen(optList[i].opt)
+			(int)(INDENT - strlen(optList[i].opt)
 			 + (optList_isBool(i) ? 0 : 2)),
 			(optList[i].arg ? optList[i].arg : ""),
 			(optList_isBool(i) ? "turn on/off " : ""),
@@ -533,12 +533,12 @@ usage(int type)
 	    if (optList[i].kw != NULL)
 		fprintf(stderr, "    %s: %*s\n",
 			optList[i].kw,
-			(INDENT - strlen(optList[i].kw)),
+			(int)(INDENT - strlen(optList[i].kw)),
 			(optList_isBool(i) ? "boolean" : optList[i].arg));
 
 #ifdef KEYSYM_RESOURCE
 	fprintf(stderr, "    " "keysym.sym" ": %*s\n",
-		(INDENT - strlen("keysym.sym")), "keysym");
+		(int)(INDENT - strlen("keysym.sym")), "keysym");
 #endif
 	fprintf(stderr, "\n    -help to list options\n    -version for the version information with options list\n\n");
 	break;
@@ -686,8 +686,8 @@ int
 my_strcasecmp(const char *s1, const char *s2)
 {
     for ( /*nil */ ; (*s1 && *s2); s1++, s2++) {
-	register int    c1 = toupper(*s1);
-	register int    c2 = toupper(*s2);
+	register int    c1 = toupper((unsigned char)*s1);
+	register int    c2 = toupper((unsigned char)*s2);
 
 	if (c1 != c2)
 	    return (c1 - c2);
@@ -739,8 +739,8 @@ parse_keysym(char *str, char *arg)
 	str += n;		/* skip `keysym.' */
     }
 /* some scanf() have trouble with a 0x prefix */
-    if (isdigit(str[0])) {
-	if (str[0] == '0' && toupper(str[1]) == 'X')
+    if (isdigit((unsigned char)str[0])) {
+	if (str[0] == '0' && toupper((unsigned char)str[1]) == 'X')
 	    str += 2;
 	if (arg) {
 	    if (sscanf(str, (strchr(str, ':') ? "%x:" : "%x"), &sym) != 1)
@@ -823,7 +823,7 @@ get_xdefaults(FILE * stream, const char 
     while ((str = fgets(buffer, sizeof(buffer), stream)) != NULL) {
 	unsigned int    entry, n;
 
-	while (*str && isspace(*str))
+	while (*str && isspace((unsigned char)*str))
 	    str++;		/* leading whitespace */
 
 	if ((str[len] != '*' && str[len] != '.') ||
