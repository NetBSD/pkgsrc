$NetBSD: patch-mojo_public_cpp_bindings_clone__traits.h,v 1.2 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/public/cpp/bindings/clone_traits.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ mojo/public/cpp/bindings/clone_traits.h
@@ -30,12 +30,12 @@ struct CloneTraits {
     } else if constexpr (std::copyable<T>) {
       return input;
     } else {
-      static_assert(
+/*      static_assert(
           false,
           "T is not copyable and has no Clone() method, so the default "
           "mojo::CloneTraits cannot be used; please make sure to include the "
           "header that defines the mojo::CloneTraits<T> specialization");
-    }
+*/    }
   }
 };
 
