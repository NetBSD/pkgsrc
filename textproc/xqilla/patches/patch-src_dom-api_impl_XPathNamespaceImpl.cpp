$NetBSD: patch-src_dom-api_impl_XPathNamespaceImpl.cpp,v 1.1 2017/10/01 09:45:50 wiz Exp $

Xerces-C 3.2.0 removed castToNode (which relied on undefined
behaviour) with a cleaner way of getting information about a node's
containing node: a new fContainingNode member.
https://sourceforge.net/p/xqilla/bugs/48/

--- src/dom-api/impl/XPathNamespaceImpl.cpp.orig	2015-05-18 17:39:00.000000000 +0000
+++ src/dom-api/impl/XPathNamespaceImpl.cpp
@@ -33,7 +33,11 @@ XERCES_CPP_NAMESPACE_USE;
 
 XPathNamespaceImpl::XPathNamespaceImpl(const XMLCh* const nsPrefix, 
 		const XMLCh* const nsUri, DOMElement *owner, DOMDocument *docOwner) 
+#if _XERCES_VERSION >= 30200 
+	: fNode(this, docOwner)
+#else
 	: fNode(docOwner)
+#endif
 {
     DOMNodeImpl *argImpl = castToNodeImpl(this);
 
@@ -54,7 +58,13 @@ XPathNamespaceImpl::XPathNamespaceImpl(c
 }
 
 XPathNamespaceImpl::XPathNamespaceImpl(const XPathNamespaceImpl &other) 
-	: fNode(other.fNode), uri(other.uri), prefix(other.prefix)
+#if _XERCES_VERSION >= 30200 
+	: fNode(this, other.fNode),
+#else
+	: fNode(other.fNode), 
+
+#endif
+	  uri(other.uri), prefix(other.prefix)
 {
 }
 
@@ -196,7 +206,11 @@ short            XPathNamespaceImpl::com
 
     //if it is a custom node and bigger than us we must ask it for the order
     if(otherType > DOMXPathNamespace::XPATH_NAMESPACE_NODE) {
+#if _XERCES_VERSION >= 30200 
+        DOMNodeImpl tmp(const_cast<XPathNamespaceImpl *>(this), 0);
+#else
         DOMNodeImpl tmp(0);
+#endif
 #if _XERCES_VERSION >= 30000
         return tmp.reverseTreeOrderBitPattern(other->compareDocumentPosition(this));
 #else
