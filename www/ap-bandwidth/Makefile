# $NetBSD: Makefile,v 1.6 2004/05/08 15:19:18 grant Exp $
#

DISTNAME=	mod_bandwidth.c
PKGNAME=	ap-bandwidth-2.0.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/
EXTRACT_SUFX=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cohprog.com/v3/bandwidth/intro-en.html
COMMENT=	Apache module for bandwidth management

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

APACHE_MODULE_NAME=	mod_bandwidth.so

DIST_SUBDIR=	${PKGNAME}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
