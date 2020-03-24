$NetBSD: patch-khtml_misc_AtomicString.cpp,v 1.1 2020/03/24 20:34:31 joerg Exp $

--- khtml/misc/AtomicString.cpp.orig	2020-03-23 22:02:19.272387221 +0000
+++ khtml/misc/AtomicString.cpp
@@ -160,7 +160,7 @@ DOMStringImpl* AtomicString::add(const Q
         return DOMStringImpl::empty();
    
     init();
-    UCharBuffer buf = { s, length }; 
+    UCharBuffer buf = { s, unsigned(length) }; 
     std::pair<HashSet<DOMStringImpl*>::iterator, bool> addResult = stringTable->add<UCharBuffer, UCharBufferTranslator>(buf);
     if (!addResult.second)
         return *addResult.first;
@@ -180,7 +180,7 @@ DOMStringImpl* AtomicString::add(const Q
         return DOMStringImpl::empty();
 
     init();
-    UCharBuffer buf = {s, length}; 
+    UCharBuffer buf = {s, unsigned(length)}; 
     std::pair<HashSet<DOMStringImpl*>::iterator, bool> addResult = stringTable->add<UCharBuffer, UCharBufferTranslator>(buf);
     if (!addResult.second)
         return *addResult.first;
