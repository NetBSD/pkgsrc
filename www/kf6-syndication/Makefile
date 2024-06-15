# $NetBSD: Makefile,v 1.3 2024/06/15 06:22:41 jperkin Exp $

DISTNAME=	syndication-${KF6VER}
PKGREVISION=	1
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	RSS/Atom parser library
LICENSE=	gnu-lgpl-v2.1 AND 2-clause-bsd

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
