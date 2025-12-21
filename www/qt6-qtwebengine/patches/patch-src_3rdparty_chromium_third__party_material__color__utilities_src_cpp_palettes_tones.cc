$NetBSD: patch-src_3rdparty_chromium_third__party_material__color__utilities_src_cpp_palettes_tones.cc,v 1.1 2025/12/21 09:38:43 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/material_color_utilities/src/cpp/palettes/tones.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/material_color_utilities/src/cpp/palettes/tones.cc
@@ -14,6 +14,8 @@
  * limitations under the License.
  */
 
+#include <cmath>
+
 #include "cpp/palettes/tones.h"
 
 #include <cmath>
