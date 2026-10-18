$NetBSD: patch-vendor_github.com_sourcegraph_zoekt_index_indexfile.go,v 1.1 2026/10/18 08:23:58 khorben Exp $

Fix build on NetBSD and illumos
https://github.com/sourcegraph/zoekt/commit/3c8b39b1ef4f8194cb912d7e6581cff9db224aa7
https://github.com/sourcegraph/zoekt/commit/44b77f9cfe9220e631c0b510c5b6155cbcc09a81

--- ./vendor/github.com/sourcegraph/zoekt/index/indexfile.go.orig	2026-09-10 11:06:35.000000000 +0000
+++ ./vendor/github.com/sourcegraph/zoekt/index/indexfile.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build linux || darwin || freebsd
+//go:build linux || darwin || freebsd || netbsd || illumos
 
 package index
 
