# $NetBSD: buildlink.mk,v 1.7 2001/11/13 21:10:46 jlam Exp $
#
# This Makefile fragment is included by packages that use kdebase2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kdebase2 to the dependency pattern
#     for the version of kdebase2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KDEBASE2_BUILDLINK_MK)
KDEBASE2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kdebase2?=	kdebase-2.[1-9]*
DEPENDS+=	${BUILDLINK_DEPENDS.kdebase2}:../../x11/kdebase2

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdebase2=kdebase
BUILDLINK_PREFIX.kdebase2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdebase2!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdebase2/PLIST

.include "../../x11/kdelibs2/buildlink.mk"

BUILDLINK_TARGETS.kdebase2=	kdebase2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.kdebase2}

pre-configure: ${BUILDLINK_TARGETS.kdebase2}
kdebase2-buildlink: _BUILDLINK_USE

.endif	# KDEBASE2_BUILDLINK_MK
