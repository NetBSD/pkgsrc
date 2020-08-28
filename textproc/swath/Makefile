# $NetBSD: Makefile,v 1.10 2020/08/28 19:35:46 scole Exp $
#

DISTNAME=	swath-0.6.1
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlwg/}
GITHUB_TAG=	f5b0a9b804cc3f4a3d40f2de3d54a99d1c0a5643

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/projects/swath
COMMENT=	Smart Word Analysis for THai
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config sh aclocal autoconf automake touch

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ./autogen.sh

post-configure:
	cd ${WRKSRC} && ${TOUCH} lib/libcompat.la

.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
