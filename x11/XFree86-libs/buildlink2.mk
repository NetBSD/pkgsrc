# $NetBSD: buildlink2.mk,v 1.9 2004/04/27 00:52:33 wiz Exp $
#
# This Makefile fragment is included by packages that use XFree86-libs.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFREE86_LIBS_BUILDLINK2_MK)
XFREE86_LIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			XFree86-libs
BUILDLINK_DEPENDS.XFree86-libs?=	XFree86-libs>=4.4.0
BUILDLINK_PKGSRCDIR.XFree86-libs?=	../../x11/XFree86-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.XFree86-libs=XFree86-libs
BUILDLINK_PREFIX.XFree86-libs_DEFAULT=	${LOCALBASE}/X11R6
BUILDLINK_FILES.XFree86-libs+=	include/DPS/*.h
BUILDLINK_FILES.XFree86-libs+=	include/GL/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/ICE/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/SM/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/Xaw/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/Xcursor/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/Xmu/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/extensions/*.h
BUILDLINK_FILES.XFree86-libs+=	include/X11/fonts/*.h
BUILDLINK_FILES.XFree86-libs+=	include/*.h
BUILDLINK_FILES.XFree86-libs+=	lib/libGLw.*
BUILDLINK_FILES.XFree86-libs+=	lib/libICE.*
BUILDLINK_FILES.XFree86-libs+=	lib/libSM.*
BUILDLINK_FILES.XFree86-libs+=	lib/libX11.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXRes.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXTrap.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXau.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXaw.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXcursor.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXdmcp.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXext.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXfont.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXfontcache.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXi.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXinerama.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXmu.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXmuu.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXp.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXpm.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXss.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXt.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXtst.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXv.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXvMC.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXxf86dga.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXxf86misc.*
BUILDLINK_FILES.XFree86-libs+=	lib/libXxf86vm.*
BUILDLINK_FILES.XFree86-libs+=	lib/libdps.*
BUILDLINK_FILES.XFree86-libs+=	lib/libdpstk.*
BUILDLINK_FILES.XFree86-libs+=	lib/libfntstubs.*
BUILDLINK_FILES.XFree86-libs+=	lib/libfontenc.*
BUILDLINK_FILES.XFree86-libs+=	lib/liboldX.*
BUILDLINK_FILES.XFree86-libs+=	lib/libpsres.*
BUILDLINK_FILES.XFree86-libs+=	lib/libxf86config.*
BUILDLINK_FILES.XFree86-libs+=	lib/libxkbfile.*
BUILDLINK_FILES.XFree86-libs+=	lib/libxkbui.*
BUILDLINK_FILES.XFree86-libs+=	lib/libGL.*
BUILDLINK_FILES.XFree86-libs+=	lib/libGLU.*
BUILDLINK_FILES.XFree86-libs+=	lib/libOSMesa.*

.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
BUILDLINK_TARGETS+=	XFree86-libs-buildlink

XFree86-libs-buildlink: _BUILDLINK_USE

.endif	# XFREE86_LIBS_BUILDLINK2_MK
