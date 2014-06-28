$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.h,v 1.3 2014/06/28 22:51:38 joerg Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.h.orig	2014-06-13 00:46:04.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.h
@@ -213,6 +213,8 @@ protected:
   static StringInfo sStringInfo[2];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 namespace mozilla {
 namespace dom {
 
