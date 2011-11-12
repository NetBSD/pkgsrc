$NetBSD: patch-bin__varnishd__cache_dir_random.c,v 1.1 2011/11/12 20:40:16 mspo Exp $

deal with missing exp2

--- bin/varnishd/cache_dir_random.c.orig	2011-10-24 07:25:09.000000000 +0000
+++ bin/varnishd/cache_dir_random.c
@@ -62,6 +62,11 @@
 #include "vsha256.h"
 #include "vend.h"
 
+#ifndef HAVE_EXP2
+ #define EXP2_32 4294967296
+ #define EXP2_31 2147483648
+#endif
+
 /*--------------------------------------------------------------------*/
 
 struct vdi_random_host {
@@ -97,7 +102,11 @@ vdi_random_sha(const char *input, ssize_
 	SHA256_Init(&ctx);
 	SHA256_Update(&ctx, input, len);
 	SHA256_Final(sign, &ctx);
+#ifndef HAVE_EXP2
+	return (vle32dec(sign) / EXP2_32);
+#else
 	return (vle32dec(sign) / exp2(32));
+#endif
 }
 
 /*
@@ -119,11 +128,19 @@ vdi_random_init_seed(const struct vdi_ra
 		break;
 	case c_hash:
 		AN(sp->digest);
+#ifndef HAVE_EXP2
+		retval = vle32dec(sp->digest) / EXP2_32;
+#else
 		retval = vle32dec(sp->digest) / exp2(32);
+#endif
 		break;
 	case c_random:
 	default:
+#ifndef HAVE_EXP2
+		retval = random() / EXP2_31;
+#else
 		retval = random() / exp2(31);
+#endif
 		break;
 	}
 	return (retval);
