# $NetBSD: buildlink2.mk,v 1.8 2004/03/29 05:05:49 jlam Exp $

.if !defined(GTKMM_BUILDLINK2_MK)
GTKMM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gtkmm
BUILDLINK_PKGBASE.gtkmm?=	gtk--
BUILDLINK_DEPENDS.gtkmm?=	gtk-->=1.2.10nb3
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtk--

EVAL_PREFIX+=			BUILDLINK_PREFIX.gtkmm=gtkmm
BUILDLINK_PREFIX.gtkmm_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkmm=		include/gdk--.h
BUILDLINK_FILES.gtkmm+=		include/gdk--/*
BUILDLINK_FILES.gtkmm+=		include/glib--.h
BUILDLINK_FILES.gtkmm+=		include/gtk--.h
BUILDLINK_FILES.gtkmm+=		include/gtk--/*
BUILDLINK_FILES.gtkmm+=		include/gtk--/private/*
BUILDLINK_FILES.gtkmm+=		lib/gtkmm/include/*
BUILDLINK_FILES.gtkmm+=		lib/libgdkmm.*
BUILDLINK_FILES.gtkmm+=		lib/libgtkmm.*

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkmm-buildlink

gtkmm-buildlink: _BUILDLINK_USE

.endif	# GTKMM_BUILDLINK2_MK
