# $NetBSD: Makefile,v 1.5 2024/11/01 12:54:50 wiz Exp $

DISTNAME=	syndication-${KF6VER}
PKGREVISION=	3
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	RSS/Atom parser library
LICENSE=	gnu-lgpl-v2.1 AND 2-clause-bsd

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
