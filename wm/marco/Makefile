# $NetBSD: Makefile,v 1.46 2024/10/20 14:04:40 wiz Exp $

PKGREVISION=	7
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	marco-${VERSION:R}.2
CATEGORIES=	wm

COMMENT=	Fork of GNOME Metacity

USE_LANGUAGES=	c99

TOOL_DEPENDS+=		gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint
DEPENDS+=		zenity3-[0-9]*:../../x11/zenity3

PKGCONFIG_OVERRIDE+=	src/libmarco-private.pc.in

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
