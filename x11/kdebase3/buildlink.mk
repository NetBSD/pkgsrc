# $NetBSD: buildlink.mk,v 1.1.1.1.2.2 2002/06/23 19:05:10 jlam Exp $
#
# This Makefile fragment is included by packages that use kdebase3.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kdebase3 to the dependency pattern
#     for the version of kdebase3 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KDEBASE3_BUILDLINK_MK)
KDEBASE3_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kdebase3?=	kdebase>=3.0
DEPENDS+=	${BUILDLINK_DEPENDS.kdebase3}:../../x11/kdebase3

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdebase3=kdebase
BUILDLINK_PREFIX.kdebase3_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdebase3!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdebase3/PLIST

.include "../../x11/kdelibs3/buildlink.mk"

BUILDLINK_TARGETS.kdebase3=	kdebase3-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.kdebase3}

pre-configure: ${BUILDLINK_TARGETS.kdebase3}
kdebase3-buildlink: _BUILDLINK_USE

.endif	# KDEBASE3_BUILDLINK_MK
