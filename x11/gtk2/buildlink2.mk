# $NetBSD: buildlink2.mk,v 1.13 2004/03/29 05:05:50 jlam Exp $

.if !defined(GTK2_BUILDLINK2_MK)
GTK2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gtk2
BUILDLINK_PKGBASE.gtk2?=	gtk2+
BUILDLINK_DEPENDS.gtk2?=	gtk2+>=2.2.4nb2
BUILDLINK_PKGSRCDIR.gtk2?=	../../x11/gtk2

EVAL_PREFIX+=		BUILDLINK_PREFIX.gtk2=gtk2
BUILDLINK_PREFIX.gtk2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtk2=	include/gtk-2.0/*/*
BUILDLINK_FILES.gtk2+=	include/gtk-2.0/*
BUILDLINK_FILES.gtk2+=	lib/gtk-2.0/*/*/*
BUILDLINK_FILES.gtk2+=	lib/gtk-2.0/*/*
BUILDLINK_FILES.gtk2+=	lib/gtk-2.0/*
BUILDLINK_FILES.gtk2+=	lib/libgdk*-2.0.*
BUILDLINK_FILES.gtk2+=	lib/libgtk*-2.0.*

USE_X11=	YES

.include "../../devel/atk/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/Xrandr/buildlink2.mk"

BUILDLINK_TARGETS+=	gtk2-buildlink

gtk2-buildlink: _BUILDLINK_USE

.endif	# GTK2_BUILDLINK2_MK
