# $NetBSD: buildlink2.mk,v 1.5 2003/12/13 00:45:26 wiz Exp $
#
# This Makefile fragment is included by packages that use libzvt.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(LIBZVT_BUILDLINK2_MK)
LIBZVT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libzvt
BUILDLINK_DEPENDS.libzvt?=		libzvt>=2.0.1nb4
BUILDLINK_PKGSRCDIR.libzvt?=		../../x11/libzvt

EVAL_PREFIX+=	BUILDLINK_PREFIX.libzvt=libzvt
BUILDLINK_PREFIX.libzvt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libzvt+=	include/libzvt-2.0/libzvt/*.h
BUILDLINK_FILES.libzvt+=	lib/libzvt-2.0.*
BUILDLINK_FILES.libzvt+=	lib/pkgconfig/libzvt-2.0.pc

.include "../../graphics/libart2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libzvt-buildlink

libzvt-buildlink: _BUILDLINK_USE

.endif	# LIBZVT_BUILDLINK2_MK
