# $NetBSD: buildlink.mk,v 1.3 2002/09/10 16:06:53 wiz Exp $
#
# This Makefile fragment is included by packages that use gtk2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtk2 to the dependency pattern
#     for the version of gtk2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTK2_BUILDLINK_MK)
GTK2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gtk2?=	gtk2+>=2.0.6nb1
DEPENDS+=		${BUILDLINK_DEPENDS.gtk2}:../../x11/gtk2

EVAL_PREFIX+=		BUILDLINK_PREFIX.gtk2=gtk2
BUILDLINK_PREFIX.gtk2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtk2=	include/gtk-2.0/*/*
BUILDLINK_FILES.gtk2+=	include/gtk-2.0/*
BUILDLINK_FILES.gtk2+=	lib/gtk-2.0/*/*/*
BUILDLINK_FILES.gtk2+=	lib/gtk-2.0/*/*
BUILDLINK_FILES.gtk2+=	lib/gtk-2.0/*
BUILDLINK_FILES.gtk2+=	lib/libgdk*-2.0.*
BUILDLINK_FILES.gtk2+=	lib/libgtk*-2.0.*

.include "../../devel/atk/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"
.include "../../devel/pango/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

BUILDLINK_TARGETS.gtk2=		gtk2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gtk2}

pre-configure: ${BUILDLINK_TARGETS.gtk2}
gtk2-buildlink: _BUILDLINK_USE

.endif	# GTK2_BUILDLINK_MK
