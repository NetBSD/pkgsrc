$NetBSD: patch-drw.c,v 1.1 2019/03/03 13:12:03 maya Exp $

Workaround FC_COLOR not being available on fontconfig < 2.11.91
(NetBSD-8.0)

This is mostly code to reject colored fonts, so ifdef'ing it out is safe.

--- drw.c.orig	2019-02-02 12:55:02.000000000 +0000
+++ drw.c
@@ -139,11 +139,13 @@ xfont_create(Drw *drw, const char *fontn
 	 * https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=916349
 	 * and lots more all over the internet.
 	 */
+#ifdef FC_COLOR
 	FcBool iscol;
 	if(FcPatternGetBool(xfont->pattern, FC_COLOR, 0, &iscol) == FcResultMatch && iscol) {
 		XftFontClose(drw->dpy, xfont);
 		return NULL;
 	}
+#endif
 
 	font = ecalloc(1, sizeof(Fnt));
 	font->xfont = xfont;
@@ -350,7 +352,9 @@ drw_text(Drw *drw, int x, int y, unsigne
 			fcpattern = FcPatternDuplicate(drw->fonts->pattern);
 			FcPatternAddCharSet(fcpattern, FC_CHARSET, fccharset);
 			FcPatternAddBool(fcpattern, FC_SCALABLE, FcTrue);
+#ifdef FC_COLOR
 			FcPatternAddBool(fcpattern, FC_COLOR, FcFalse);
+#endif
 
 			FcConfigSubstitute(NULL, fcpattern, FcMatchPattern);
 			FcDefaultSubstitute(fcpattern);
