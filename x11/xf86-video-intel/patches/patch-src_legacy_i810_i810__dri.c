$NetBSD: patch-src_legacy_i810_i810__dri.c,v 1.1 2015/04/20 13:39:00 khorben Exp $

CID 1107540: Make the code safe avoiding random stack access. In
the first loop where there is a singleton point to pptSrc, only
access that singleton, no matter what.

November 2013 patch from NetBSD xsrc:
http://mail-index.netbsd.org/source-changes/2013/11/14/msg049188.html

--- src/legacy/i810/i810_dri.c.orig	2014-08-29 09:33:11.000000000 +0000
+++ src/legacy/i810/i810_dri.c
@@ -1104,10 +1104,17 @@ I810DRIMoveBuffers(WindowPtr pParent, DD
 	    while ((pboxNext >= pbox) && (pboxBase->y1 == pboxNext->y1))
 	       pboxNext--;
 	    pboxTmp = pboxNext + 1;
-	    pptTmp = pptSrc + (pboxTmp - pbox);
-	    while (pboxTmp <= pboxBase) {
-	       *pboxNew1++ = *pboxTmp++;
-	       *pptNew1++ = *pptTmp++;
+	    if (pptSrc == &ptOldOrg) {
+		if (pboxTmp <= pboxBase) {
+	          *pboxNew1++ = *pboxTmp;
+	          *pptNew1++ = *pptSrc;
+		}
+	    } else {
+	       pptTmp = pptSrc + (pboxTmp - pbox);
+	       while (pboxTmp <= pboxBase) {
+	          *pboxNew1++ = *pboxTmp++;
+	          *pptNew1++ = *pptTmp++;
+	       }
 	    }
 	    pboxBase = pboxNext;
 	 }
