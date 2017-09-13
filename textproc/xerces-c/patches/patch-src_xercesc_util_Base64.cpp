$NetBSD: patch-src_xercesc_util_Base64.cpp,v 1.1 2017/09/13 21:10:35 joerg Exp $

--- src/xercesc/util/Base64.cpp.orig	2017-09-12 21:32:28.227017311 +0000
+++ src/xercesc/util/Base64.cpp
@@ -15,6 +15,8 @@
  * limitations under the License.
  */
 
+#define __STDC_LIMIT_MACROS
+
 // ---------------------------------------------------------------------------
 //  Includes
 // ---------------------------------------------------------------------------
@@ -23,6 +25,7 @@
 #include <xercesc/util/Janitor.hpp>
 #include <xercesc/internal/XMLReader.hpp>
 #include <xercesc/framework/MemoryManager.hpp>
+#include <cstdint>
 
 XERCES_CPP_NAMESPACE_BEGIN
 
