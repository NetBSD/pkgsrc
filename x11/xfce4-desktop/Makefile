# $NetBSD: Makefile,v 1.75 2019/03/09 19:33:45 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-4.13.3
PKGNAME=	xfce4-desktop-4.13.3
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/xfce/xfdesktop/4.13/

HOMEPAGE=	http://docs.xfce.org/xfce/xfdesktop/start
COMMENT=	Xfce desktop background manager

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
