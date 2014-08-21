$NetBSD: patch-sip_plasma_glapplet.sip,v 1.1 2014/08/21 21:34:33 wiz Exp $

--- sip/plasma/glapplet.sip.orig	2014-01-02 19:29:04.000000000 +0000
+++ sip/plasma/glapplet.sip
@@ -18,8 +18,13 @@
 // 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 
 //force
+
+%Feature PyKDE_GLuint
+
+%If (PyKDE_GLuint)
 typedef unsigned int GLuint;
 typedef unsigned int GLenum;
+%End
 
 namespace Plasma
 {
