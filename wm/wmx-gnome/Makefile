# $NetBSD: Makefile,v 1.6 2004/05/01 17:57:54 snj Exp $

PKGNAME=	wmx-gnome-${WMX_VERS}
CATEGORIES+=	gnome
COMMENT=	Another X11 window manager based on wm2, with GNOME compliance

USE_BUILDLINK3=	yes
USE_GCC_SHLIB=	# defined

.include "../../wm/wmx/Makefile.common"

CPPFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CPPFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_COMPLIANCE=True
CXXFLAGS+=	-DCONFIG_GNOME_BUTTON_COMPLIANCE=True

.include "../../mk/bsd.pkg.mk"
