$NetBSD: patch-content_svg_content_src_SVGComponentTransferFunctionElement.h,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- content/svg/content/src/SVGComponentTransferFunctionElement.h.orig	2014-05-14 23:29:58.000000000 +0000
+++ content/svg/content/src/SVGComponentTransferFunctionElement.h
@@ -74,6 +74,8 @@ protected:
   static EnumInfo sEnumInfo[1];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(SVGComponentTransferFunctionElement, NS_SVG_FE_COMPONENT_TRANSFER_FUNCTION_ELEMENT_CID)
+
 } // namespace dom
 } // namespace mozilla
 
