# $NetBSD: Makefile,v 1.1.1.1 2000/01/17 14:13:42 agc Exp $

DISTNAME=	asp2php0.73.4
PKGNAME=	asp2php-0.73.4
CATEGORIES=	www
MASTER_SITES=	http://home.i1.net/~naken/asp2php/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.i1.net/~naken/asp2php/

WRKSRC=		${WRKDIR}/asp2php

ALL_TARGET=	default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asp2php ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unipiss ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
