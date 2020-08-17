# $NetBSD: Makefile,v 1.14 2020/08/17 20:20:19 leot Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
PKGREVISION=	1
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

.include "../../wm/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
