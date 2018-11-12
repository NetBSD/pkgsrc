# $NetBSD: Makefile,v 1.11 2018/11/12 03:53:00 ryoon Exp $

PKGREVISION= 5
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
