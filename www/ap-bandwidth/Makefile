# $NetBSD: Makefile,v 1.3 2003/06/02 01:16:09 jschauma Exp $
#

DISTNAME=	mod_bandwidth.c
PKGNAME=	ap-bandwidth-2.0.5
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/
EXTRACT_SUFX=	# empty

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://cohprog.com/v3/bandwidth/intro-en.html
COMMENT=	Apache module for bandwidth management

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_bandwidth.so

DIST_SUBDIR=	${PKGNAME}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
