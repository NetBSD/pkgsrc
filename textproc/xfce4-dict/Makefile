# $NetBSD: Makefile,v 1.34 2024/09/30 23:04:18 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-dict-0.8.7
CATEGORIES=	textproc
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-dict/0.8/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-dict
COMMENT=	Xfce dictionary application

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
