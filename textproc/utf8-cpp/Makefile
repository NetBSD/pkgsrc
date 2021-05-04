# $NetBSD: Makefile,v 1.1 2021/05/04 14:24:33 prlw1 Exp $

DISTNAME=	utf8-cpp-2.3.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jjones646/}
GITHUB_TAG=	v2.3.4

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/jjones646/utf8-cpp/
COMMENT=	UTF-8 header library for C++
LICENSE=	boost-license

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	include/utf8

do-install:
	${INSTALL_DATA} ${WRKSRC}/source/utf8.h ${DESTDIR}${PREFIX}/include
.for f in checked.h core.h unchecked.h
	${INSTALL_DATA} ${WRKSRC}/source/utf8/${f} ${DESTDIR}${PREFIX}/include/utf8
.endfor

.include "../../mk/bsd.pkg.mk"
