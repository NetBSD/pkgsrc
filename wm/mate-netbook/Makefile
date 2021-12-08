# $NetBSD: Makefile,v 1.24 2021/12/08 16:06:51 adam Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-netbook-${VERSION:R}.0
CATEGORIES=	wm

COMMENT=	Simple window management tool for MATE desktop

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-netbook

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/mate-netbook/xdg/autostart/mate-maximus-autostart.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-maximus-autostart.desktop
.include "../../devel/glib2/schemas.mk"

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../x11/libfakekey/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
