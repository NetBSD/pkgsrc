# $NetBSD: Makefile,v 1.18 2018/03/12 11:15:49 wiz Exp $

DISTNAME=	frameworkintegration-${KF5VER}
PKGREVISION=	3
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
