# $NetBSD: buildlink.mk,v 1.1 2001/07/29 06:28:59 jlam Exp $
#
# This Makefile fragment is included by packages that use Xbae.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.Xbae to the dependency pattern
#     for the version of Xbae desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XBAE_BUILDLINK_MK)
XBAE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.Xbae?=	Xbae>=4.8.4
DEPENDS+=			${BUILDLINK_DEPENDS.Xbae}:../../x11/Xbae

EVAL_PREFIX+=			BUILDLINK_PREFIX.Xbae=Xbae
BUILDLINK_PREFIX.Xbae_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.Xbae=		include/Xbae/*
BUILDLINK_FILES.Xbae+=		lib/libXbae.*

.include "../../x11/lesstif/buildlink.mk"

BUILDLINK_TARGETS.Xbae=	Xbae-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.Xbae}

pre-configure: ${BUILDLINK_TARGETS.Xbae}
Xbae-buildlink: _BUILDLINK_USE

.endif	# XBAE_BUILDLINK_MK
