# $NetBSD: Makefile,v 1.43 2026/01/27 08:40:42 wiz Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-dict-0.8.9
CATEGORIES=	textproc
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-dict/0.8/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-dict
COMMENT=	Xfce dictionary application

USE_TOOLS+=	autoconf automake autoreconf gdbus-codegen

TOOL_DEPENDS+=	xfce4-dev-tools>=4.20.0:../../devel/xfce4-dev-tools

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
