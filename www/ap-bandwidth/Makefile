# $NetBSD: Makefile,v 1.7 2005/02/24 11:52:30 wiz Exp $
#

DISTNAME=	mod_bandwidth.c
PKGNAME=	ap-bandwidth-2.0.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/
EXTRACT_SUFX=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cohprog.com/mod_bandwidth.html
COMMENT=	Apache module for bandwidth management

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

APACHE_MODULE_NAME=	mod_bandwidth.so

DIST_SUBDIR=	${PKGNAME}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
