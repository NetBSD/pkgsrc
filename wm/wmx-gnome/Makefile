# $NetBSD: Makefile,v 1.8 2004/11/13 22:04:53 jlam Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

.include "../../wm/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
