# $NetBSD: Makefile,v 1.2 2015/04/25 14:25:24 tnn Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	garcon-0.4.0
PKGNAME=	xfce4-garcon-0.4.0
CATEGORIES=	x11

HOMEPAGE=	https://wiki.xfce.org/dev/garcon
COMMENT=	Xfce menu library

CONF_FILES=	${XFCE4_EGBASE}/menus/xfce-applications.menu \
		${PKG_SYSCONFDIR}/menus/xfce-applications.menu

MAKE_DIRS+=	${XFCE4_EGBASE}/menus

.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
