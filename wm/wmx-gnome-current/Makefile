# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:56 wiz Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
CATEGORIES+=	gnome

COMMENT=	another X11 window manager based on wm2, with GNOME compliance

CPPFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../wm/wmx-current/Makefile.common"
