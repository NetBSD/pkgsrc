# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:24:01 jlam Exp $

.if !defined(XFORMS_BUILDLINK2_MK)
XFORMS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xforms
BUILDLINK_DEPENDS.xforms?=	xforms>=0.9999
BUILDLINK_PKGSRCDIR.xforms?=	../../x11/xforms

EVAL_PREFIX+=			BUILDLINK_PREFIX.xforms=xforms
BUILDLINK_PREFIX.xforms_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xforms=		include/X11/forms.h
BUILDLINK_FILES.xforms+=	lib/libforms.*
BUILDLINK_FILES.xforms+=	lib/libxforms.*

.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	xforms-buildlink

xforms-buildlink: _BUILDLINK_USE

.endif	# XFORMS_BUILDLINK2_MK
