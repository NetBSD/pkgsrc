# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:52 wiz Exp $

.if !defined(GNOME_CORE_BUILDLINK2_MK)
GNOME_CORE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-core
BUILDLINK_DEPENDS.gnome-core?=		gnome-core>=1.4.0.6nb1
BUILDLINK_PKGSRCDIR.gnome-core?=	../../x11/gnome-core

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-core=gnome-core
BUILDLINK_PREFIX.gnome-core_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-core=	include/applet-widget.h
BUILDLINK_FILES.gnome-core+=	include/gnome-panel.h
BUILDLINK_FILES.gnome-core+=	include/status-docklet.h
BUILDLINK_FILES.gnome-core+=	lib/libfish_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libgen_util_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libpanel_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libpanel_status.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-core-buildlink

gnome-core-buildlink: _BUILDLINK_USE

.endif	# GNOME_CORE_BUILDLINK2_MK
