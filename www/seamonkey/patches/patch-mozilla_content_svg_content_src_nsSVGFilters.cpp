$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.cpp,v 1.3 2014/06/28 22:51:38 joerg Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.cpp.orig	2014-06-13 00:45:21.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.cpp
@@ -67,8 +67,6 @@ nsSVGElement::LengthInfo nsSVGFE::sLengt
 NS_IMPL_ADDREF_INHERITED(nsSVGFE,nsSVGFEBase)
 NS_IMPL_RELEASE_INHERITED(nsSVGFE,nsSVGFEBase)
 
-NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
-
 NS_INTERFACE_MAP_BEGIN(nsSVGFE)
    // nsISupports is an ambiguous base of nsSVGFE so we have to work
    // around that
@@ -248,8 +246,6 @@ nsSVGElement::EnumInfo SVGComponentTrans
 NS_IMPL_ADDREF_INHERITED(SVGComponentTransferFunctionElement,SVGComponentTransferFunctionElementBase)
 NS_IMPL_RELEASE_INHERITED(SVGComponentTransferFunctionElement,SVGComponentTransferFunctionElementBase)
 
-NS_DEFINE_STATIC_IID_ACCESSOR(SVGComponentTransferFunctionElement, NS_SVG_FE_COMPONENT_TRANSFER_FUNCTION_ELEMENT_CID)
-
 NS_INTERFACE_MAP_BEGIN(SVGComponentTransferFunctionElement)
    // nsISupports is an ambiguous base of nsSVGFE so we have to work
    // around that
