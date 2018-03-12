# $NetBSD: Makefile,v 1.8 2018/03/12 11:17:40 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-dict-0.8.0
CATEGORIES=	textproc
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-dict/0.8/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-dict
COMMENT=	Xfce dictionary application

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
