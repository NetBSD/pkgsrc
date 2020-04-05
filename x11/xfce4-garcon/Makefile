# $NetBSD: Makefile,v 1.23 2020/04/05 22:59:00 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.7.0
DISTNAME=	garcon-${VERSION}
PKGNAME=	xfce4-garcon-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/garcon/${VERSION:R}/

HOMEPAGE=	https://wiki.xfce.org/dev/garcon
COMMENT=	Xfce menu library

PKGCONFIG_OVERRIDE=	garcon/garcon-1.pc.in
PKGCONFIG_OVERRIDE=	garcon/garcon-2.pc.in
PKGCONFIG_OVERRIDE+=	garcon-gtk/garcon-gtk2.pc.in
PKGCONFIG_OVERRIDE+=	garcon-gtk/garcon-gtk3.pc.in

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${EGDIR} ${EGDIR}/menus ${PKG_SYSCONFDIR}/menus

CONF_FILES=		${EGDIR}/menus/xfce-applications.menu \
			${PKG_SYSCONFDIR}/menus/xfce-applications.menu

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
