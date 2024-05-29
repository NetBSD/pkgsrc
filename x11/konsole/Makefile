# $NetBSD: Makefile,v 1.80 2024/05/29 16:35:04 adam Exp $

DISTNAME=	konsole-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	http://kde.org/applications/system/konsole/
COMMENT=	Terminal emulator for the K Desktop Environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.68.0:../../x11/kinit

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	data/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/konsolerc \
		${PKG_SYSCONFDIR}/xdg/konsolerc

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
