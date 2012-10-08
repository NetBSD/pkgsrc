# $NetBSD: Makefile,v 1.12 2012/10/08 12:42:25 asau Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
PKGREVISION=	2
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

.include "../../wm/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
