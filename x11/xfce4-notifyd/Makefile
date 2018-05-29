# $NetBSD: Makefile,v 1.13 2018/05/29 21:24:20 youri Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-notifyd-0.4.2
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-notifyd/0.4/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-notifyd
COMMENT=	XFCE Notify daemon

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

DESKTOP_FILE=	xfce4-notifyd.desktop

SUBST_CLASSES=		prefix
SUBST_MESSAGE.prefix=	Fixing path
SUBST_STAGE.prefix=	pre-install
SUBST_FILES.prefix=	xfce4-notifyd/${DESKTOP_FILE}
SUBST_VARS.prefix=	PREFIX

pre-configure:
	cp ${FILESDIR}/${DESKTOP_FILE} \
	    ${WRKSRC}/xfce4-notifyd/${DESKTOP_FILE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/xfce4-notifyd/${DESKTOP_FILE} \
	    ${PKG_SYSCONFDIR}/xdg/autostart/${DESKTOP_FILE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
