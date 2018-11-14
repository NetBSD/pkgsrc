# $NetBSD: Makefile,v 1.9 2018/11/14 22:22:47 kleink Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-menus-${VERSION}
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
