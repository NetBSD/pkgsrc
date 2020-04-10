# $NetBSD: Makefile,v 1.25 2020/04/10 20:46:21 gutteridge Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.6.0
DISTNAME=	xfce4-notifyd-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-notifyd/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-notifyd
COMMENT=	XFCE Notify daemon

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

DESKTOP_FILE=	xfce4-notifyd.desktop
EGDIR=		share/examples/xfce4-notifyd
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${EGDIR}/${DESKTOP_FILE} \
		${PKG_SYSCONFDIR}/xdg/autostart/${DESKTOP_FILE}

INSTALLATION_DIRS+=	${EGDIR}

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/${DESKTOP_FILE} \
	    > ${WRKSRC}/${DESKTOP_FILE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/${DESKTOP_FILE} \
	    ${DESTDIR}${PREFIX}/${EGDIR}/${DESKTOP_FILE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
