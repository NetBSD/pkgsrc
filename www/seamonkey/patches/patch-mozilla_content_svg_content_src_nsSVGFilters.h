$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.h,v 1.1 2014/05/18 21:28:28 joerg Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.h.orig	2014-03-19 01:41:48.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.h
@@ -213,6 +213,8 @@ protected:
   static StringInfo sStringInfo[2];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 namespace mozilla {
 namespace dom {
 
