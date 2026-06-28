$NetBSD: patch-libastro_dbfmt.c,v 1.1 2026/06/28 00:51:59 gdt Exp $

Fix ctype(3) UB.  Cherry-picked from https://github.com/XEphem/XEphem/pull/126

--- libastro/dbfmt.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ libastro/dbfmt.c
@@ -196,11 +196,11 @@ db_tle (char *name, char *l1, char *l2, 
 	/* check for correct line numbers, macthing satellite numbers and
 	 * correct checksums.
 	 */
-	while (isspace(*l1))
+	while (isspace((unsigned char)*l1))
 	    l1++;
 	if (*l1 != '1')
 	    return (-1);
-	while (isspace(*l2))
+	while (isspace((unsigned char)*l2))
 	    l2++;
 	if (*l2 != '2')
 	    return (-1);
@@ -218,7 +218,7 @@ db_tle (char *name, char *l1, char *l2, 
 	op->o_type = EARTHSAT;
 
 	/* name, sans leading and trailing whitespace */
-	while (isspace(*name))
+	while (isspace((unsigned char)*name))
 	    name++;
 	i = strcspn (name, "\r\n");
 	while (i > 0 && name[i-1] == ' ')
@@ -331,7 +331,7 @@ dbline_candidate (char *buf)
 {
 	char c = buf[0];
 
-	return (c == '#' || c == '!' || isspace(c) ? -1 : 0);
+	return (c == '#' || c == '!' || isspace((unsigned char)c) ? -1 : 0);
 }
 
 /* return 0 if TLE checksum is ok, else -1 */
@@ -345,7 +345,7 @@ tle_sum (char *l)
 	    char c = *l++;
 	    if (c == '\0')
 		return (-1);
-	    if (isdigit(c))
+	    if (isdigit((unsigned char)c))
 		sum += c - '0';
 	    else if (c == '-')
 		sum++;
@@ -492,11 +492,11 @@ crack_e (Obj *op, char *flds[MAXFLDS], i
 
 	/* magnitude model gk or HG(default). allow prefixes in either field */
 	op->e_mag.whichm = flds[11][0] == 'g' ? MAG_gk : MAG_HG;
-	if (isdigit(flds[11][0]))
+	if (isdigit((unsigned char)flds[11][0]))
 	    op->e_mag.m1 = (float) atod(&flds[11][0]);
 	else
 	    op->e_mag.m1 = (float) atod(&flds[11][1]);
-	if (isdigit(flds[12][0]))
+	if (isdigit((unsigned char)flds[12][0]))
 	    op->e_mag.m2 = (float) atod(&flds[12][0]);
 	else
 	    op->e_mag.m2 = (float) atod(&flds[12][1]);
@@ -741,7 +741,7 @@ crack_B (Obj *op, char *flds[MAXFLDS], i
 		op->b_bo.bo_P /= 365.25;
 		break;
 	    default:
-		if (c != ' ' && !isdigit(c)) {
+		if (c != ' ' && !isdigit((unsigned char)c)) {
 		    if (whynot)
 			sprintf (whynot,"%s: B period suffix not Y, D or H: %c",
 								enm(flds), c);
