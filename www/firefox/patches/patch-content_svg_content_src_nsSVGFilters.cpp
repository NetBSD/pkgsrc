$NetBSD: patch-content_svg_content_src_nsSVGFilters.cpp,v 1.3 2014/06/14 16:20:07 joerg Exp $

--- content/svg/content/src/nsSVGFilters.cpp.orig	2014-06-06 01:15:20.000000000 +0000
+++ content/svg/content/src/nsSVGFilters.cpp
@@ -67,7 +67,7 @@ nsSVGElement::LengthInfo nsSVGFE::sLengt
 NS_IMPL_ADDREF_INHERITED(nsSVGFE,nsSVGFEBase)
 NS_IMPL_RELEASE_INHERITED(nsSVGFE,nsSVGFEBase)
 
-NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+//NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
 
 NS_INTERFACE_MAP_BEGIN(nsSVGFE)
    // nsISupports is an ambiguous base of nsSVGFE so we have to work
@@ -248,8 +248,6 @@ nsSVGElement::EnumInfo SVGComponentTrans
 NS_IMPL_ADDREF_INHERITED(SVGComponentTransferFunctionElement,SVGComponentTransferFunctionElementBase)
 NS_IMPL_RELEASE_INHERITED(SVGComponentTransferFunctionElement,SVGComponentTransferFunctionElementBase)
 
-NS_DEFINE_STATIC_IID_ACCESSOR(SVGComponentTransferFunctionElement, NS_SVG_FE_COMPONENT_TRANSFER_FUNCTION_ELEMENT_CID)
-
 NS_INTERFACE_MAP_BEGIN(SVGComponentTransferFunctionElement)
    // nsISupports is an ambiguous base of nsSVGFE so we have to work
    // around that
