# $NetBSD: Makefile,v 1.58 2023/10/24 22:11:28 wiz Exp $

DISTNAME=	libmediawiki-5.37.0
PKGREVISION=	16
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_KDE:=libmediawiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	Mediawiki C++ interface for KDE
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
