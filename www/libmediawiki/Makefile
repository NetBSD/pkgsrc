# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 20:57:24 markd Exp $
#

PKGNAME=	libmediawiki-2.5.0
DISTNAME=	digikam-2.5.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	Mediawiki C++ interface for KDE
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libmediawiki.pc.cmake

WRKSRC=			${WRKDIR}/${DISTNAME}/extra/libmediawiki

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
