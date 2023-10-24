# $NetBSD: Makefile,v 1.17 2023/10/24 22:11:19 wiz Exp $

DISTNAME=	qore-json-module-1.8.2
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-json
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
COMMENT=	JSON module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	native

CMAKE_USE_GNU_INSTALL_DIRS=	no

#This is needed in order to comply the with MIT license and binary distribution
#Install docs
INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/qore/module.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
