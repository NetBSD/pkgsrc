# $NetBSD: Makefile,v 1.1.1.1 2003/02/16 11:19:03 grant Exp $

DISTNAME=	mod_throttle312
PKGNAME=	ap-throttle-3.1.2
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Apache module for limiting bandwidth usage

WRKSRC=         ${WRKDIR}/${PKGNAME:S/ap-/mod_/}

USE_BUILDLINK2=	# defined
APACHE_MODULE=	# defined

do-build:
	cd ${WRKSRC} && ${APXS} -c -o mod_throttle.so mod_throttle.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_throttle.so

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
