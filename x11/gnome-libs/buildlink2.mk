# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:40:31 jlam Exp $

.if !defined(GNOME_LIBS_BUILDLINK2_MK)
GNOME_LIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-libs
BUILDLINK_DEPENDS.gnome-libs?=		gnome-libs>=1.4.1.4
BUILDLINK_PKGSRCDIR.gnome-libs?=	../../x11/gnome-libs

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-libs=gnome-libs
BUILDLINK_PREFIX.gnome-libs_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-libs=	include/gnome-1.0/gnome.h
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/gtk-xmhtml/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libart_lgpl/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libgnome/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libgnomeui/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libgnorba/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/popt-gnome.h
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/zvt/*
BUILDLINK_FILES.gnome-libs+=	lib/gnome-libs/*/*
BUILDLINK_FILES.gnome-libs+=	lib/libart_lgpl.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnome.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnomesupport.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnomeui.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnorba.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnorbagtk.*
BUILDLINK_FILES.gnome-libs+=	lib/libgtkxmhtml.*
BUILDLINK_FILES.gnome-libs+=	lib/libzvt.*

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=		gnome-libs-buildlink

gnome-libs-buildlink: _BUILDLINK_USE

.endif	# GNOME_LIBS_BUILDLINK2_MK
