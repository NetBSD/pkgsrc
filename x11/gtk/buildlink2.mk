# $NetBSD: buildlink2.mk,v 1.13 2004/03/29 05:05:49 jlam Exp $

.if !defined(GTK_BUILDLINK2_MK)
GTK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gtk
BUILDLINK_PKGBASE.gtk?=		gtk+
BUILDLINK_DEPENDS.gtk?=		gtk+>=1.2.10
BUILDLINK_RECOMMENDED.gtk?=	gtk+>=1.2.10nb6
BUILDLINK_PKGSRCDIR.gtk?=	../../x11/gtk

EVAL_PREFIX+=		BUILDLINK_PREFIX.gtk=gtk
BUILDLINK_PREFIX.gtk_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtk=	include/gdk/*
BUILDLINK_FILES.gtk+=	include/gtk/*
BUILDLINK_FILES.gtk+=	include/gtk-1*/*/*
BUILDLINK_FILES.gtk+=	lib/libgdk.*
BUILDLINK_FILES.gtk+=	lib/libgtk.*

USE_X11=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"

BUILDLINK_TARGETS+=	gtk-buildlink

gtk-buildlink: _BUILDLINK_USE

.endif	# GTK_BUILDLINK2_MK
