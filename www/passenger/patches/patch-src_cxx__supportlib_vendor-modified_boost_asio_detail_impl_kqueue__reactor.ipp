$NetBSD: patch-src_cxx__supportlib_vendor-modified_boost_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2019/12/25 00:15:42 joerg Exp $

--- src/cxx_supportlib/vendor-modified/boost/asio/detail/impl/kqueue_reactor.ipp.orig	2019-12-23 18:29:53.306488810 +0000
+++ src/cxx_supportlib/vendor-modified/boost/asio/detail/impl/kqueue_reactor.ipp
@@ -28,6 +28,9 @@
 #include <boost/asio/detail/push_options.hpp>
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+#if defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 999001500)
 # define BOOST_ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
