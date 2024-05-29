# $NetBSD: Makefile,v 1.3 2024/05/29 16:35:04 adam Exp $

DISTNAME=	kirigami-addons-0.11.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE:=kirigami-addons/}

HOMEPAGE=	https://invent.kde.org/libraries/kirigami-addons
COMMENT=	Add-ons for the Kirigami framework
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
