# $NetBSD: Makefile,v 1.30 2021/07/11 03:32:48 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	marco-${VERSION:R}.2
PKGREVISION=	1
CATEGORIES=	wm

COMMENT=	Fork of GNOME Metacity

USE_LANGUAGES=	c99

BUILD_DEPENDS+=		gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint
DEPENDS+=		zenity-[0-9]*:../../x11/zenity

PKGCONFIG_OVERRIDE+=	src/libmarco-private.pc.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
