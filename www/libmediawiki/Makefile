# $NetBSD: Makefile,v 1.18 2013/11/10 03:19:27 markd Exp $
#

PKGNAME=	libmediawiki-3.5.0
DISTNAME=	digikam-3.5.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	Mediawiki C++ interface for KDE
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	libmediawiki.pc.cmake

WRKSRC=			${WRKDIR}/${DISTNAME}/extra/libmediawiki

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
