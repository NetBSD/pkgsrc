$NetBSD: patch-xmltooling_util_XMLHelper.cpp,v 1.1 2012/11/18 01:53:07 joerg Exp $

--- xmltooling/util/XMLHelper.cpp.orig	2012-11-18 00:26:45.000000000 +0000
+++ xmltooling/util/XMLHelper.cpp
@@ -440,7 +440,7 @@ ostream& XMLHelper::serialize(const DOMN
     return out;
 }
 
-ostream& xmltooling::operator<<(ostream& ostr, const DOMNode& node)
+ostream& xercesc_3_1::operator<<(ostream& ostr, const DOMNode& node)
 {
     return XMLHelper::serialize(&node, ostr);
 }
