# $NetBSD: hacks.mk,v 1.1 2025/04/25 21:25:03 nia Exp $

.if !defined(PALEMOON_HACKS_MK)
PALEMOON_HACKS_MK=	# defined

### [Sat Aug  3 11:00:17 CEST 2024 : nia]
### NetBSD 9.x does not expose all standard C++ functions with default
### source visibility.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		netbsd-source
CXXFLAGS+=		-D_NETBSD_SOURCE
.endif

.endif
