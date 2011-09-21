$NetBSD: patch-Symbol_Symbol.xs,v 1.1 2011/09/21 14:59:32 obache Exp $

* fixes build with perl-5.14.

--- Symbol/Symbol.xs.orig	2000-12-22 06:02:32.000000000 +0000
+++ Symbol/Symbol.xs
@@ -30,7 +30,7 @@ static void undef(SV *ref)
 	    has_proto = TRUE;
 
 	cv_undef(cv);
-	CvGV(cv) = gv;   /* let user-undef'd sub keep its identity */
+	CvGV_set(cv, gv);   /* let user-undef'd sub keep its identity */
         if(has_proto) 
             SvPOK_on(cv); /* otherwise we get `Prototype mismatch:' */
 
