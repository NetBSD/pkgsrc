$NetBSD: patch-sip_kio_kautomount.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

build with sip 4.19 

--- sip/kio/kautomount.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kio/kautomount.sip
@@ -20,7 +20,7 @@
 // along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 
-class KAutoMount : QObject
+class KAutoMount : QObject /Abstract/
 {
 %TypeHeaderCode
 #include <kautomount.h>
@@ -42,7 +42,7 @@ private:
 // KAutoMount
 
 
-class KAutoUnmount : QObject
+class KAutoUnmount : QObject /Abstract/
 {
 %TypeHeaderCode
 #include <kautomount.h>
