# $NetBSD: Makefile,v 1.3 2016/06/11 23:01:59 youri Exp $

DISTNAME=	lxlauncher-0.2.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://wiki.lxde.org/en/LXLauncher
COMMENT=	Program launcher for small screens
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool pkg-config msgfmt

PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=	${PKG_SYSCONFDIR}/lxlauncher \
		${PKG_SYSCONFDIR}/menus

EGDIR=			share/examples

CONF_FILES=	${EGDIR}/lxlauncher/gtkrc			\
		${PKG_SYSCONFDIR}/lxlauncher/gtkrc 		\
		${EGDIR}/lxlauncher/gtk.css			\
		${PKG_SYSCONFDIR}/lxlauncher/gtk.css 		\
		${EGDIR}/lxlauncher/settings.conf		\
		${PKG_SYSCONFDIR}/lxlauncher/settings.conf	\
		${EGDIR}/menus/lxlauncher-applications.menu 	\
		${PKG_SYSCONFDIR}/menus/lxlauncher-applications.menu

.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
