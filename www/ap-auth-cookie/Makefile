# $NetBSD: Makefile,v 1.37 2006/02/05 23:11:16 joerg Exp $
#
# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one.

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap-auth-cookie-1.9
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kciLink.com/pub/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://ftp.kciLink.com/pub/mod_auth_cookie.txt
COMMENT=	Cookie-based authentication for Apache

WRKSRC=		${WRKDIR}

EXTRACT_CMD=	${DO_NADA}

APACHE_MODULE_NAME=	mod_auth_cookie.so

DIST_SUBDIR=	${PKGNAME_NOREV}

post-extract:
	@(${ECHO} '#include "ap_compat.h"'; ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
