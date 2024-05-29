# $NetBSD: Makefile,v 1.27 2024/05/29 16:34:40 adam Exp $

DISTNAME=	qore-xml-module-1.8.1
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-xml
GITHUB_RELEASE=	v${PKGVERSION_NOREV}


MAINTAINER=	nros@NetBSD.org
COMMENT=	XML module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1 OR mit

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	native

REPLACE_QORE=	bin/soaputil bin/webdav-server

CMAKE_USE_GNU_INSTALL_DRIS=	no
#This is needed in order to comply the with MIT license and binary distribution
INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/qore/application.mk"
.include "../../lang/qore/module.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
