# $NetBSD: Makefile,v 1.17 2018/01/28 20:10:38 wiz Exp $

DISTNAME=	frameworkintegration-${KF5VER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Provide components to allow applications to integrate with a KDE Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

DEPENDS+=	noto-ttf-[0-9]*:../../fonts/noto-ttf
#DEPENDS+=	oxygen-fonts-[0-9]*:../../fonts/oxygen-fonts

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kpackage/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
