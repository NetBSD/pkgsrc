$NetBSD: patch-src_bitmap_bdfread.c,v 1.1.2.2 2014/01/07 17:11:53 tron Exp $

From aeabb3efa6905e11c479e2e5319f2b6b3ab22009 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Mon, 23 Dec 2013 18:34:02 -0800
Subject: [PATCH:libXfont 1/2] CVE-2013-XXXX: unlimited sscanf can overflow
 stack buffer in bdfReadCharacters()

Fixes cppcheck warning:
 [lib/libXfont/src/bitmap/bdfread.c:341]: (warning)
  scanf without field width limits can crash with huge input data.

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Matthieu Herrb <matthieu@herrb.eu>
Reviewed-by: Jeremy Huddleston Sequoia <jeremyhu@apple.com>
---
 src/bitmap/bdfread.c |    2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

From f8b21df399fbedd08da88752181b8a290a38d890 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Mon, 23 Dec 2013 19:01:11 -0800
Subject: [PATCH:libXfont 2/2] Limit additional sscanf strings to fit buffer
 sizes

None of these could currently result in buffer overflow, as the input
and output buffers were the same size, but adding limits helps ensure
we keep it that way, if we ever resize any of these in the future.

Fixes cppcheck warnings:
 [lib/libXfont/src/bitmap/bdfread.c:547]: (warning)
  scanf without field width limits can crash with huge input data.
 [lib/libXfont/src/bitmap/bdfread.c:553]: (warning)
  scanf without field width limits can crash with huge input data.
 [lib/libXfont/src/bitmap/bdfread.c:636]: (warning)
  scanf without field width limits can crash with huge input data.

Signed-off-by: Alan Coopersmith <alan.coopersmith@oracle.com>
Reviewed-by: Matthieu Herrb <matthieu@herrb.eu>
Reviewed-by: Jeremy Huddleston Sequoia <jeremyhu@apple.com>
---
 src/bitmap/bdfread.c |   14 +++++++++++---
 1 file changed, 11 insertions(+), 3 deletions(-)

--- src/bitmap/bdfread.c.orig	2013-07-21 23:54:01.000000000 +0000
+++ src/bitmap/bdfread.c
@@ -69,6 +69,7 @@ from The Open Group.
 #define INDICES 256
 #define MAXENCODING 0xFFFF
 #define BDFLINELEN  1024
+#define BDFLINESTR  "%1023s" /* scanf specifier to read a BDFLINELEN string */
 
 static Bool bdfPadToTerminal(FontPtr pFont);
 extern int  bdfFileLineNum;
@@ -338,7 +339,7 @@ bdfReadCharacters(FontFilePtr file, Font
 	char        charName[100];
 	int         ignore;
 
-	if (sscanf((char *) line, "STARTCHAR %s", charName) != 1) {
+	if (sscanf((char *) line, "STARTCHAR %99s", charName) != 1) {
 	    bdfError("bad character name in BDF file\n");
 	    goto BAILOUT;	/* bottom of function, free and return error */
 	}
@@ -544,13 +545,18 @@ bdfReadHeader(FontFilePtr file, bdfFileS
     unsigned char        lineBuf[BDFLINELEN];
 
     line = bdfGetLine(file, lineBuf, BDFLINELEN);
-    if (!line || sscanf((char *) line, "STARTFONT %s", namebuf) != 1 ||
+    if (!line ||
+        sscanf((char *) line, "STARTFONT " BDFLINESTR, namebuf) != 1 ||
 	    !bdfStrEqual(namebuf, "2.1")) {
 	bdfError("bad 'STARTFONT'\n");
 	return (FALSE);
     }
     line = bdfGetLine(file, lineBuf, BDFLINELEN);
-    if (!line || sscanf((char *) line, "FONT %[^\n]", pState->fontName) != 1) {
+#if MAXFONTNAMELEN != 1024
+# error "need to adjust sscanf length limit to be MAXFONTNAMELEN - 1"
+#endif
+    if (!line ||
+        sscanf((char *) line, "FONT %1023[^\n]", pState->fontName) != 1) {
 	bdfError("bad 'FONT'\n");
 	return (FALSE);
     }
@@ -633,7 +639,9 @@ bdfReadProperties(FontFilePtr file, Font
 	while (*line && isspace(*line))
 	    line++;
 
-	switch (sscanf((char *) line, "%s%s%s", namebuf, secondbuf, thirdbuf)) {
+	switch (sscanf((char *) line,
+                       BDFLINESTR BDFLINESTR BDFLINESTR,
+                       namebuf, secondbuf, thirdbuf)) {
 	default:
 	    bdfError("missing '%s' parameter value\n", namebuf);
 	    goto BAILOUT;
