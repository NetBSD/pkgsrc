# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/04 14:40:40 recht Exp $

.if !defined(XRANDR_BUILDLINK2_MK)
XRANDR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Xrandr
BUILDLINK_DEPENDS.Xrandr?=		Xrandr>=1.0.1
BUILDLINK_PKGSRCDIR.Xrandr?=		../../x11/Xrandr

EVAL_PREFIX+=	BUILDLINK_PREFIX.Xrandr=Xrandr
BUILDLINK_PREFIX.Xrandr_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Xrandr+=	include/X11/extensions/Xrandr.h
BUILDLINK_FILES.Xrandr+=	lib/libXrandr.*

_IS_BUILTIN_XRANDR=	0

USE_X11=	YES

.include "../../x11/randrext/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	Xrandr-buildlink

Xrandr-buildlink: _BUILDLINK_USE

.endif	# XRANDR_BUILDLINK2_MK
