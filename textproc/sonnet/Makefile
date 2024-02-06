# $NetBSD: Makefile,v 1.71 2024/02/06 10:46:31 markd Exp $

DISTNAME=	sonnet-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Spelling framework for Qt5
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
