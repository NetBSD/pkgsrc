$NetBSD: patch-examples_tiles-simple.h,v 1.1 2013/04/30 22:32:43 joerg Exp $

--- examples/tiles-simple.h.orig	2013-04-30 21:45:40.000000000 +0000
+++ examples/tiles-simple.h
@@ -21,8 +21,15 @@
  * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
-#include <list>
+#include <ciso646>
+#ifdef _LIBCPP_VERSION
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
+#include <list>
 #include <gtkmm.h>
 #include "gtkmm-utils/tile.h"
 #include "gtkmm-utils/tile-view.h"
@@ -44,7 +51,7 @@ protected:
 
     Gtk::VBox vbox_;
     Gtk::Util::TileView tile_view_;
-    std::list<std::tr1::shared_ptr<Gtk::Util::Tile> > tiles_;
+    std::list<shared_ptr<Gtk::Util::Tile> > tiles_;
 
     Gtk::CheckButton show_navigation_;
     // tpp = tiles per page
