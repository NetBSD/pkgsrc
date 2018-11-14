# $NetBSD: Makefile,v 1.73 2018/11/14 22:22:51 kleink Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-4.12.4
PKGNAME=	xfce4-desktop-4.12.4
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/xfce/xfdesktop/4.12/

HOMEPAGE=	http://docs.xfce.org/xfce/xfdesktop/start
COMMENT=	Xfce desktop background manager

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
