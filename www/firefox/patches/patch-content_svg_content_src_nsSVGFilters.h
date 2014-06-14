$NetBSD: patch-content_svg_content_src_nsSVGFilters.h,v 1.3 2014/06/14 16:20:07 joerg Exp $

--- content/svg/content/src/nsSVGFilters.h.orig	2014-06-06 01:15:20.000000000 +0000
+++ content/svg/content/src/nsSVGFilters.h
@@ -148,6 +148,8 @@ protected:
   static LengthInfo sLengthInfo[4];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 typedef nsSVGElement SVGFEUnstyledElementBase;
 
 class SVGFEUnstyledElement : public SVGFEUnstyledElementBase
