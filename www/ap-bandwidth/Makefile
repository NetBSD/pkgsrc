# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:47 jmmv Exp $
#

DISTNAME=	mod_bandwidth.c
PKGNAME=	ap-bandwidth-2.0.5
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/
EXTRACT_SUFX=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cohprog.com/v3/bandwidth/intro-en.html
COMMENT=	Apache module for bandwidth management

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_bandwidth.so

DIST_SUBDIR=	${PKGNAME}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
