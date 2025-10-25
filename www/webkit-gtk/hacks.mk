# $NetBSD: hacks.mk,v 1.4 2025/10/25 14:45:27 tsutsui Exp $

.if !defined(WEBKIT_GTK_HACKS_MK)
WEBKIT_GTK_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### gcc-10.5.0 in NetBSD/earmv7hf 10.1 gets "virtual memory exhausted:
### Cannot allocate memory" with -O2.
.if ${MACHINE_PLATFORM:MNetBSD-*-*arm*} && ${CC_VERSION:Mgcc-10.*}
PKG_HACKS+=		optimisation
BUILDLINK_TRANSFORM+=	opt:-O[0-9]*:-O
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UNIFIED_BUILDS=OFF
.endif

.endif	# WEBKIT_GTK_HACKS_MK
