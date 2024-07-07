# $NetBSD: hacks.mk,v 1.1 2024/07/07 10:16:20 nia Exp $

.if !defined(CCTZ_HACKS_MK)
CCTZ_HACKS_MK=		# defined

### [Sun Jul  7 12:15:50 CEST 2024]
### NetBSD 9.x does not expose all standard C++ functions with default
### source visibility.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		netbsd-source
CXXFLAGS+=		-D_NETBSD_SOURCE
.endif

.endif
