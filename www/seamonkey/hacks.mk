# $NetBSD: hacks.mk,v 1.7 2024/08/10 10:03:58 nia Exp $

.if !defined(SEAMONKEY_HACKS_MK)
SEAMONKEY_HACKS_MK=	# defined

### [Sat Aug 10 12:02:34 CEST 2024 : nia]
### NetBSD 9.x does not expose all standard C++ functions with default
### source visibility.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		netbsd-source
CXXFLAGS+=		-D_NETBSD_SOURCE
.endif

.endif
