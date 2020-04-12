# $NetBSD: Makefile,v 1.71 2020/04/12 08:29:15 adam Exp $

DISTNAME=	rsibreak-0.12.11
PKGREVISION=	4
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_KDE:=rsibreak/0.12/}

HOMEPAGE=	https://userbase.kde.org/RSIBreak/
COMMENT=	RSI management tool
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{AUTOSTART_INSTALL_DIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/rsibreak_autostart.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/rsibreak_autostart.desktop

.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
