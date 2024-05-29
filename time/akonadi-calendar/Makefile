# $NetBSD: Makefile,v 1.9 2024/05/29 16:34:42 adam Exp $

DISTNAME=	akonadi-calendar-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Akonadi calendar integration
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	reminder-daemon/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_AUTOSTARTDIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.kalendarac.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.kalendarac.desktop

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
