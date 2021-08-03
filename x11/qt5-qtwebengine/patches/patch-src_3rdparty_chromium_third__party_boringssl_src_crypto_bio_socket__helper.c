$NetBSD: patch-src_3rdparty_chromium_third__party_boringssl_src_crypto_bio_socket__helper.c,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/boringssl/src/crypto/bio/socket_helper.c.orig	2020-07-15 19:01:31.000000000 +0000
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/bio/socket_helper.c
@@ -12,8 +12,8 @@
  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
 
-#undef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 200112L
+//#undef _POSIX_C_SOURCE
+//#define _POSIX_C_SOURCE 200112L
 
 #include <openssl/bio.h>
 #include <openssl/err.h>
