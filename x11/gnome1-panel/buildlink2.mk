# $NetBSD: buildlink2.mk,v 1.4 2003/11/12 01:31:52 salo Exp $
#
# This Makefile fragment is included by packages that use gnome-panel.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_PANEL_BUILDLINK2_MK)
GNOME_PANEL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-panel
BUILDLINK_DEPENDS.gnome-panel?=		gnome-panel>=1.4.2nb3
BUILDLINK_PKGSRCDIR.gnome-panel?=		../../x11/gnome1-panel

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-panel=gnome-panel
BUILDLINK_PREFIX.gnome-panel_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-panel+=	include/applet-widget.h
BUILDLINK_FILES.gnome-panel+=	include/gnome-panel.h
BUILDLINK_FILES.gnome-panel+=	include/status-docklet.h
BUILDLINK_FILES.gnome-panel+=	lib/appletsConf.sh
BUILDLINK_FILES.gnome-panel+=	lib/dockletsConf.sh
BUILDLINK_FILES.gnome-panel+=	lib/libpanel_applet.*
BUILDLINK_FILES.gnome-panel+=	lib/libpanel_status.*

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/gnome-pixmaps/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-panel-buildlink

gnome-panel-buildlink: _BUILDLINK_USE

.endif	# GNOME_PANEL_BUILDLINK2_MK
