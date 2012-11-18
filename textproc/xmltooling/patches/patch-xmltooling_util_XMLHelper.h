$NetBSD: patch-xmltooling_util_XMLHelper.h,v 1.1 2012/11/18 01:53:07 joerg Exp $

--- xmltooling/util/XMLHelper.h.orig	2012-11-18 00:23:44.000000000 +0000
+++ xmltooling/util/XMLHelper.h
@@ -352,16 +352,6 @@ namespace xmltooling {
     };
 
     /**
-     * Serializes the DOM node provided to a stream using UTF-8 encoding and
-     * the default XML serializer available. No manipulation or formatting is applied.
-     *
-     * @param n      node to serialize
-     * @param ostr   stream to serialize element into
-     * @return reference to output stream
-     */
-    extern XMLTOOL_API std::ostream& operator<<(std::ostream& ostr, const xercesc::DOMNode& n);
-
-    /**
      * Marshalls and serializes the XMLObject provided to a stream using UTF-8 encoding and
      * the default XML serializer available. No manipulation or formatting is applied.
      *
@@ -374,4 +364,16 @@ namespace xmltooling {
     extern XMLTOOL_API std::ostream& operator<<(std::ostream& ostr, const XMLObject& obj);
 };
 
+namespace xercesc_3_1 {
+    /**
+     * Serializes the DOM node provided to a stream using UTF-8 encoding and
+     * the default XML serializer available. No manipulation or formatting is applied.
+     *
+     * @param n      node to serialize
+     * @param ostr   stream to serialize element into
+     * @return reference to output stream
+     */
+    extern XMLTOOL_API std::ostream& operator<<(std::ostream& ostr, const xercesc::DOMNode& n);
+};
+
 #endif /* __xmltooling_xmlhelper_h__ */
