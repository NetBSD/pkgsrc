# $NetBSD: Makefile,v 1.3 2001/07/14 02:27:35 jlam Exp $

.include "../../wm/wmx-current/Makefile.common"

PKGNAME=	wmx-gnome-${WMX_VERS}
CATEGORIES+=	gnome

COMMENT=	another X11 window manager based on wm2, with GNOME compliance

CPPFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
