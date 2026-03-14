$NetBSD: patch-mojo_public_cpp_bindings_clone__traits.h,v 1.1 2026/03/14 12:40:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/public/cpp/bindings/clone_traits.h.orig	2026-03-11 22:12:25.000000000 +0000
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
 
