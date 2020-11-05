# $NetBSD: Makefile,v 1.35 2020/11/05 09:07:16 ryoon Exp $

DISTNAME=	kxmlgui-${KF5VER}
PKGREVISION=	3
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	User configurable main windows
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}/ui:{KDE_INSTALL_DATAROOTDIR}/examples/kxmlgui:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/ui
CONF_FILES+=	${PREFIX}/share/examples/kxmlgui/ui_standards.rc \
		${PKG_SYSCONFDIR}/xdg/ui/ui_standards.rc

.include "../../lang/python/tool.mk"
.include "../../misc/attica-qt5/buildlink3.mk"
.include "../../x11/kglobalaccel/buildlink3.mk"
.include "../../x11/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
