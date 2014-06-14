$NetBSD: patch-content_svg_content_src_SVGComponentTransferFunctionElement.h,v 1.3 2014/06/14 16:20:07 joerg Exp $

--- content/svg/content/src/SVGComponentTransferFunctionElement.h.orig	2014-06-06 01:15:20.000000000 +0000
+++ content/svg/content/src/SVGComponentTransferFunctionElement.h
@@ -77,6 +77,8 @@ protected:
   static EnumInfo sEnumInfo[1];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(SVGComponentTransferFunctionElement, NS_SVG_FE_COMPONENT_TRANSFER_FUNCTION_ELEMENT_CID)
+
 } // namespace dom
 } // namespace mozilla
 
