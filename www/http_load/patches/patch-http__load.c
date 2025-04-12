$NetBSD: patch-http__load.c,v 1.2 2025/04/12 07:04:18 adam Exp $

Initialize protocol family.

--- http_load.c.orig	2006-03-12 19:17:03.000000000 +0000
+++ http_load.c
@@ -785,6 +785,7 @@ read_sip_file( char* sip_file )
 		argv0, sips[num_sips].str );
 	    exit( 1 );
 	    }
+	sips[num_sips].sa_in.sin_family = AF_INET;
 	++num_sips;
 	}
     }
