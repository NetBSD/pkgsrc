$NetBSD: patch-Xlib_____init____.py,v 1.1 2011/08/22 11:57:14 wiz Exp $

Get rid of "import string". From upstream SVN 123.

--- Xlib/__init__.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/__init__.py
@@ -18,13 +18,11 @@
 #    along with this program; if not, write to the Free Software
 #    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
-import string
-
 __version__ = (0, 12)
 
 __version_extra__ = ''
 
-__version_string__ = string.join(map(str, __version__), '.') + __version_extra__
+__version_string__ = '.'.join(map(str, __version__)) + __version_extra__
 
 __all__ = [
     'X',
