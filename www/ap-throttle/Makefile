# $NetBSD: Makefile,v 1.3 2003/02/17 17:50:12 grant Exp $

DISTNAME=	mod_throttle312
PKGNAME=	ap-throttle-3.1.2
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Apache module for limiting bandwidth usage

USE_BUILDLINK2=	YES

WRKSRC=         ${WRKDIR}/${PKGNAME:S/ap-/mod_/}

APACHE_MODULE_NAME=	mod_throttle.so
APACHE_MODULE_SRC=	mod_throttle.c

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
