# $NetBSD: Makefile,v 1.14 2010/02/20 14:58:44 joerg Exp $
#

DISTNAME=	mod_bandwidth.c
PKGNAME=	ap13-bandwidth-2.0.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cohprog.com/pub/apache/module/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cohprog.com/mod_bandwidth.html
COMMENT=	Apache module for bandwidth management

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-bandwidth-[0-9]*

WRKSRC=		${WRKDIR}

APACHE_MODULE_NAME=	mod_bandwidth.so

DIST_SUBDIR=	${PKGNAME_NOREV}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
