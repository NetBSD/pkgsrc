# $NetBSD: hacks.mk,v 1.1 2007/04/19 01:08:51 xtraeme Exp $
#
# Disable the option precomp headers, seems to barf on
# NetBSD mipseb machines... reported by jmcneill@NetBSD.org.

.if !defined(WXGTK_HACKS_MK)
WXGTK_HACKS_MK=		# defined

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "mipseb"
PKG_HACKS+=		disable-precomp-headers
CONFIGURE_ARGS+=        --disable-precomp-headers
.endif

.endif # WXGTK_HACKS_MK
