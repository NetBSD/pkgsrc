# $NetBSD: buildlink2.mk,v 1.2 2004/02/02 14:15:27 xtraeme Exp $
#
# This Makefile fragment is included by packages that use XFree86-libs.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFREE86_LIBS_BUILDLINK2_MK)
XFREE86_LIBS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=			XFree86-libs
BUILDLINK_DEPENDS.XFree86-libs?=		XFree86-libs>=4.3.0
BUILDLINK_PKGSRCDIR.XFree86-libs?=		../../x11/XFree86-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.XFree86-libs=XFree86-libs
BUILDLINK_PREFIX.XFree86-libs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/DPS/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/GL/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/ICE/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/SM/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/Xaw/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/Xcursor/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/Xmu/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/extensions/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/X11/fonts/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/include/*.h
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/X11/locale/lib/common/ximcp.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/X11/locale/lib/common/xlcDef.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/X11/locale/lib/common/xlcUTF8Load.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/X11/locale/lib/common/xlibi18n.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/X11/locale/lib/common/xlocale.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/X11/locale/lib/common/xomGeneric.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libGLw.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libICE.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libSM.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libX11.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXRes.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXTrap.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXau.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXaw.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXcursor.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXdmcp.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXext.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXfont.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXfontcache.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXi.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXinerama.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXmu.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXmuu.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXp.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXpm.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXrandr.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXrender.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXss.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXt.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXtst.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXv.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXvMC.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXxf86dga.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXxf86misc.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libXxf86vm.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libdps.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libdpstk.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libfntstubs.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libfontenc.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/liboldX.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libpsres.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libxf86config.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libxkbfile.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libxkbui.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libGL.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libGLU.*
BUILDLINK_FILES.XFree86-libs+=	X11R6/lib/libOSMesa.*

.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
BUILDLINK_TARGETS+=	XFree86-libs-buildlink

XFree86-libs-buildlink: _BUILDLINK_USE

.endif	# XFREE86_LIBS_BUILDLINK2_MK
