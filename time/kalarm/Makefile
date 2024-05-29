# $NetBSD: Makefile,v 1.8 2024/05/29 16:34:43 adam Exp $

DISTNAME=	kalarm-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	time

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Personal alarm scheduler
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge perl:run

SUBST_CLASSES+=         xdg
SUBST_STAGE.xdg=        pre-configure
SUBST_MESSAGE.xdg=      Install via examples dir.
SUBST_FILES.xdg=        src/CMakeLists.txt
SUBST_SED.xdg=          -e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/kalarm.autostart.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/kalarm.autostart.desktop

REPLACE_PERL+=	src/kconf_update/*.pl

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../mail/mailcommon/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
