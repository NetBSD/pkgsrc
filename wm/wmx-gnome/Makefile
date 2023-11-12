# $NetBSD: Makefile,v 1.16 2023/11/12 13:23:53 wiz Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
PKGREVISION=	3
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

.include "../../wm/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
