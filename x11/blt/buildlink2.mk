# $NetBSD: buildlink2.mk,v 1.2 2004/01/13 23:29:07 xtraeme Exp $
#
# This Makefile fragment is included by packages that use blt.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(BLT_BUILDLINK2_MK)
BLT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			blt
BUILDLINK_DEPENDS.blt?=		blt>=2.4o
BUILDLINK_PKGSRCDIR.blt?=		../../x11/blt

EVAL_PREFIX+=	BUILDLINK_PREFIX.blt=blt
BUILDLINK_PREFIX.blt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.blt+=	include/blt.h
BUILDLINK_FILES.blt+=	lib/libBLT.*
BUILDLINK_FILES.blt+=	lib/libBLT24.*

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

BUILDLINK_TARGETS+=	blt-buildlink

blt-buildlink: _BUILDLINK_USE

.endif	# BLT_BUILDLINK2_MK
