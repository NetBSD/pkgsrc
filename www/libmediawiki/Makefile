# $NetBSD: Makefile,v 1.68 2025/10/23 20:39:47 wiz Exp $

DISTNAME=	libmediawiki-5.37.0
PKGREVISION=	26
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
