# $NetBSD: buildlink.mk,v 1.7 2001/08/23 04:24:22 jlam Exp $
#
# This Makefile fragment is included by packages that use Xaw3d.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.Xaw3d to the dependency pattern
#     for the version of Xaw3d desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XAW3D_BUILDLINK_MK)
XAW3D_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.Xaw3d?=	Xaw3d-1.5
DEPENDS+=	${BUILDLINK_DEPENDS.Xaw3d}:../../x11/Xaw3d

EVAL_PREFIX+=			BUILDLINK_PREFIX.Xaw3d=Xaw3d
BUILDLINK_PREFIX.Xaw3d_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.Xaw3d=		include/X11/X11/Xaw3d/*	# for OpenWindows
BUILDLINK_FILES.Xaw3d+=		include/X11/Xaw3d/*
BUILDLINK_FILES.Xaw3d+=		lib/libXaw3d.*

BUILDLINK_TARGETS.Xaw3d+=	Xaw3d-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.Xaw3d}

LIBXAW?=	-L${BUILDLINK_DIR}/lib -lXaw3d
MAKE_ENV+=	LIBXAW="${LIBXAW}"

pre-configure: ${BUILDLINK_TARGETS.Xaw3d}
Xaw3d-buildlink: _BUILDLINK_USE

.endif	# XAW3D_BUILDLINK_MK
