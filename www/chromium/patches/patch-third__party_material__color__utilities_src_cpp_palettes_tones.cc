$NetBSD: patch-third__party_material__color__utilities_src_cpp_palettes_tones.cc,v 1.2 2025/05/16 16:08:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/material_color_utilities/src/cpp/palettes/tones.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ third_party/material_color_utilities/src/cpp/palettes/tones.cc
@@ -14,6 +14,8 @@
  * limitations under the License.
  */
 
+#include <cmath>
+
 #include "cpp/palettes/tones.h"
 
 #include <cmath>
