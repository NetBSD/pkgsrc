# $NetBSD: hacks.mk,v 1.1.1.1 2008/09/22 19:44:05 joerg Exp $
#
# Disable the precompiled headers on NetBSD mipseb and sparc64
# machines, otherwise wxGTK will not compile there.
#   mipseb reported by jmcneill@NetBSD.org.
#   sparc64 reported by jdc@NetBSD.org.


.if !defined(WXGTK_HACKS_MK)
WXGTK_HACKS_MK=		# defined

.if ${OPSYS} == "NetBSD" && \
    (${MACHINE_ARCH} == "mipseb" || \
    ${MACHINE_ARCH} == "sparc64")
PKG_HACKS+=		disable-precomp-headers
CONFIGURE_ARGS+=        --disable-precomp-headers
.endif

.endif # WXGTK_HACKS_MK
