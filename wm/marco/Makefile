# $NetBSD: Makefile,v 1.52 2026/01/20 08:27:51 wiz Exp $

PKGREVISION=	12
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	marco-${VERSION:R}.2
CATEGORIES=	wm

COMMENT=	Fork of GNOME Metacity

USE_LANGUAGES=	c99

TOOL_DEPENDS+=		gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint
DEPENDS+=		zenity3-[0-9]*:../../x11/zenity3

PKGCONFIG_OVERRIDE+=	src/libmarco-private.pc.in

CFLAGS+=	-Wno-incompatible-pointer-types

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
