# $NetBSD: buildlink.mk,v 1.4 2002/04/17 04:46:24 fredb Exp $
#
# This Makefile fragment is included by packages that use xforms.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.xforms to the dependency pattern
#     for the version of xforms desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XFORMS_BUILDLINK_MK)
XFORMS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.xforms?=	xforms>=0.9999
DEPENDS+=	${BUILDLINK_DEPENDS.xforms}:../../x11/xforms

EVAL_PREFIX+=			BUILDLINK_PREFIX.xforms=xforms
BUILDLINK_PREFIX.xforms_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xforms=		include/X11/forms.h
BUILDLINK_FILES.xforms+=	lib/libforms.*
BUILDLINK_FILES.xforms+=	lib/libxforms.*

.include "../../graphics/xpm/buildlink.mk"

BUILDLINK_TARGETS.xforms=	xforms-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.xforms}

pre-configure: ${BUILDLINK_TARGETS.xforms}
xforms-buildlink: _BUILDLINK_USE

.endif	# XFORMS_BUILDLINK_MK
