# $NetBSD: buildlink2.mk,v 1.3 2004/03/15 17:30:18 recht Exp $
#
# This Makefile fragment is included by packages that use randrext.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(RANDREXT_BUILDLINK2_MK)
RANDREXT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=			randrext
# Xrandr won't build without the X Extension library which is only present
# in XFree86>=4.3.
# For this reason we don't need the header files.
.  if exists(${X11BASE}/include/X11/extensions/extutil.h)
BUILDLINK_DEPENDS.randrext?=		randrext>=1.0
BUILDLINK_PKGSRCDIR.randrext?=		../../x11/randrext

EVAL_PREFIX+=	BUILDLINK_PREFIX.randrext=randrext
BUILDLINK_PREFIX.randrext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.randrext+=	include/X11/extensions/randr.h
BUILDLINK_FILES.randrext+=	include/X11/extensions/randrproto.h
. else
BUILDLINK_PREFIX.randrext=	${X11BASE}
BUILDLINK_PREFIX.randrext_DEFAULT=	${X11BASE}
. endif

BUILDLINK_TARGETS+=	randrext-buildlink

randrext-buildlink: _BUILDLINK_USE

.endif	# RANDREXT_BUILDLINK2_MK
