# $NetBSD: Makefile,v 1.15 2018/08/22 09:48:06 wiz Exp $
#

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notifyd-0.4.2
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-notifyd/0.4/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-notifyd
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
