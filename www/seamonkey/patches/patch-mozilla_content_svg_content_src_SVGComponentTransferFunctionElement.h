$NetBSD: patch-mozilla_content_svg_content_src_SVGComponentTransferFunctionElement.h,v 1.1 2014/05/18 21:28:28 joerg Exp $

--- mozilla/content/svg/content/src/SVGComponentTransferFunctionElement.h.orig	2014-05-17 22:38:37.000000000 +0000
+++ mozilla/content/svg/content/src/SVGComponentTransferFunctionElement.h
@@ -76,6 +76,7 @@ protected:
   static nsSVGEnumMapping sTypeMap[];
   static EnumInfo sEnumInfo[1];
 };
+NS_DEFINE_STATIC_IID_ACCESSOR(SVGComponentTransferFunctionElement, NS_SVG_FE_COMPONENT_TRANSFER_FUNCTION_ELEMENT_CID)
 
 } // namespace dom
 } // namespace mozilla
