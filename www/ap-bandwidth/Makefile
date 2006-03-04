# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:56 jlam Exp $
#

DISTNAME=	mod_bandwidth.c
PKGNAME=	ap-bandwidth-2.0.6
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cohprog.com/mod_bandwidth.html
COMMENT=	Apache module for bandwidth management

WRKSRC=		${WRKDIR}

APACHE_MODULE_NAME=	mod_bandwidth.so

DIST_SUBDIR=	${PKGNAME_NOREV}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
