$NetBSD: patch-src_dom-api_impl_XPathDocumentImpl.cpp,v 1.1 2017/10/01 09:45:50 wiz Exp $

Xerces-C 3.2.0 removed castToNode (which relied on undefined
behaviour) with a cleaner way of getting information about a node's
containing node: a new fContainingNode member.
https://sourceforge.net/p/xqilla/bugs/48/

--- src/dom-api/impl/XPathDocumentImpl.cpp.orig	2015-05-18 17:38:59.000000000 +0000
+++ src/dom-api/impl/XPathDocumentImpl.cpp
@@ -62,7 +62,11 @@ DOMNode *XPathDocumentImpl::insertBefore
     if (thisNodeImpl->isReadOnly())
         throw DOMException(DOMException::NO_MODIFICATION_ALLOWED_ERR, 0, getMemoryManager());
 
+#if _XERCES_VERSION >= 30200
+    DOMNode* thisNode = fParent.fContainingNode;
+#else
     DOMNode* thisNode = castToNode(&fParent);
+#endif
     if (newChild->getOwnerDocument() != thisNode)
         throw DOMException(DOMException::WRONG_DOCUMENT_ERR, 0, getMemoryManager());
 
