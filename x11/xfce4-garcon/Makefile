# $NetBSD: Makefile,v 1.14 2018/11/12 03:53:14 ryoon Exp $

PKGREVISION= 5
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	garcon-0.6.1
PKGNAME=	xfce4-garcon-0.6.1
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/garcon/0.6/

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
