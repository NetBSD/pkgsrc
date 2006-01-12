# $NetBSD: Makefile,v 1.9 2006/01/12 18:27:53 rillig Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
PKGREVISION=	1
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

.include "../../wm/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
