# $NetBSD: buildlink2.mk,v 1.2 2004/03/15 17:30:18 recht Exp $

.if !defined(XRANDR_BUILDLINK2_MK)
XRANDR_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=			Xrandr
# Xrandr won't build without the X Extension library which is only present
# in XFree86>=4.3.
.  if exists(${X11BASE}/include/X11/extensions/extutil.h)
BUILDLINK_DEPENDS.Xrandr?=		Xrandr>=1.0.1
BUILDLINK_PKGSRCDIR.Xrandr?=		../../x11/Xrandr

EVAL_PREFIX+=	BUILDLINK_PREFIX.Xrandr=Xrandr
BUILDLINK_PREFIX.Xrandr_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Xrandr+=	include/X11/extensions/Xrandr.h
BUILDLINK_FILES.Xrandr+=	lib/libXrandr.*

_IS_BUILTIN_XRANDR=	0
.  else
BUILDLINK_PREFIX.Xrandr=	${X11BASE}
BUILDLINK_PREFIX.Xrandr_DEFAULT=	${X11BASE}
.  endif

USE_X11=	YES

.include "../../x11/randrext/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	Xrandr-buildlink

Xrandr-buildlink: _BUILDLINK_USE

.endif	# XRANDR_BUILDLINK2_MK
