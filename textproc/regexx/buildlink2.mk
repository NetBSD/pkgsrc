# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/15 08:53:09 rh Exp $
#
# This Makefile fragment is included by packages that use regexx.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(REGEXX_BUILDLINK2_MK)
REGEXX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			regexx
BUILDLINK_DEPENDS.regexx?=		regexx>=0.98.1
BUILDLINK_PKGSRCDIR.regexx?=		../../textproc/regexx

EVAL_PREFIX+=	BUILDLINK_PREFIX.regexx=regexx
BUILDLINK_PREFIX.regexx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.regexx+=	include/regexx.hh
BUILDLINK_FILES.regexx+=	include/split.hh
BUILDLINK_FILES.regexx+=	lib/libregexx.*

.include "../../devel/pcre/buildlink2.mk"

BUILDLINK_TARGETS+=	regexx-buildlink

regexx-buildlink: _BUILDLINK_USE

.endif	# REGEXX_BUILDLINK2_MK
