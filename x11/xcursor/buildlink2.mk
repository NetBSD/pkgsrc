# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/16 08:51:42 recht Exp $

.if !defined(XCURSOR_BUILDLINK2_MK)
XCURSOR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xcursor
BUILDLINK_DEPENDS.xcursor?=		xcursor>=1.1.1
BUILDLINK_PKGSRCDIR.xcursor?=		../../x11/xcursor

EVAL_PREFIX+=	BUILDLINK_PREFIX.xcursor=xcursor
BUILDLINK_PREFIX.xcursor_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xcursor+=	include/X11/Xcursor/Xcursor.h
BUILDLINK_FILES.xcursor+=	lib/libXcursor.*

USE_X11=	yes

.include "../../x11/Xfixes/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	xcursor-buildlink

xcursor-buildlink: _BUILDLINK_USE

.endif	# XCURSOR_BUILDLINK2_MK
