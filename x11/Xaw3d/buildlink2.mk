# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:54 jlam Exp $
#
# This Makefile fragment is included by packages that use Xaw3d.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.Xaw3d to the dependency pattern
#     for the version of Xaw3d desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(XAW3D_BUILDLINK2_MK)
XAW3D_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.Xaw3d?=	Xaw3d-1.5
DEPENDS+=	${BUILDLINK_DEPENDS.Xaw3d}:../../x11/Xaw3d

EVAL_PREFIX+=			BUILDLINK_PREFIX.Xaw3d=Xaw3d
BUILDLINK_PREFIX.Xaw3d_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.Xaw3d=		include/X11/X11/Xaw3d/*	# for OpenWindows
BUILDLINK_FILES.Xaw3d+=		include/X11/Xaw3d/*
BUILDLINK_FILES.Xaw3d+=		lib/libXaw3d.*

BUILDLINK_TARGETS+=	Xaw3d-buildlink

LIBXAW?=	-L${BUILDLINK_PREFIX.Xaw3d}/lib -lXaw3d

Xaw3d-buildlink: _BUILDLINK_USE

.endif	# XAW3D_BUILDLINK2_MK
