# $NetBSD: Makefile,v 1.6 2017/06/23 17:17:44 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-desktop-${VERSION}
CATEGORIES=	x11

COMMENT=	MATE desktop library

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	libmate-desktop/mate-desktop-2.0.pc.in

REPLACE_SH+=	tools/mate-gsettings-toggle

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
