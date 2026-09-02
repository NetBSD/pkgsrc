# $NetBSD: Makefile,v 1.42 2026/09/02 19:05:20 wiz Exp $

PKGREVISION= 15
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-menus-${VERSION:R}.1
CATEGORIES=	x11

COMMENT=	Implementation of the desktop menu specification for MATE

TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection

PKGCONFIG_OVERRIDE+=	libmenu/libmate-menu.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-introspection

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-menus

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/mate-menus/xdg/menus/mate-applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-applications.menu
CONF_FILES+=	${PREFIX}/share/examples/mate-menus/xdg/menus/mate-settings.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-settings.menu

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
