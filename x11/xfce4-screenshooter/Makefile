# $NetBSD: Makefile,v 1.9 2017/02/06 13:56:13 wiz Exp $

PKGREVISION= 7
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-screenshooter-1.8.2
CATEGORIES=	misc
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-screenshooter/1.8/

HOMEPAGE=	http://archive.xfce.org/src/apps/xfce4-screenshooter/1.8/
COMMENT=	Xfce screenshoot application

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
