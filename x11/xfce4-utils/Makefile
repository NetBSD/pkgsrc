# $NetBSD: Makefile,v 1.57 2014/05/05 00:48:37 ryoon Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-utils-${XFCE4_VERSION}
PKGNAME=	xfce4-utils-${XFCE4_VERSION}
PKGREVISION=	22
CATEGORIES=	x11
COMMENT=	Xfce utilities

DEPENDS+=	p5-XML-Parser>=2.36:../../textproc/p5-XML-Parser

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-xsession-prefix=${PREFIX}

BUILD_DEFS+=		PKG_SYSCONFBASE
USE_TOOLS+=		xinit:run

PKG_SYSCONFSUBDIR=	xdg
EGDIR=			${XFCE4_EGBASE}

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${EGDIR} ${EGDIR}/autostart
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/it
MAKE_DIRS+=	${PREFIX}/share/xsessions

CONF_FILES=		${EGDIR}/xinitrc ${PKG_SYSCONFDIR}/xfce4/xinitrc
CONF_FILES+=		${EGDIR}/autostart/xfconf-migration-4.6.desktop \
			${PKG_SYSCONFDIR}/autostart/xfconf-migration-4.6.desktop

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
