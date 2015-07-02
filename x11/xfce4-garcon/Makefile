# $NetBSD: Makefile,v 1.4 2015/07/02 14:13:29 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	garcon-0.5.0
PKGNAME=	xfce4-garcon-0.5.0
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/garcon/0.5/

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

.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
