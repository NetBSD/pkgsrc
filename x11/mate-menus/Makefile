# $NetBSD: Makefile,v 1.2 2016/06/13 23:08:31 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-menus-${MATE_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils

COMMENT=	Implementation of the desktop menu specification for MATE

PKGCONFIG_OVERRIDE+=	libmenu/libmate-menu.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-menus

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/mate-menus/xdg/menus/mate-applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-applications.menu
CONF_FILES+=	${PREFIX}/share/examples/mate-menus/xdg/menus/mate-settings.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-settings.menu

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
