# $NetBSD: Makefile,v 1.29 2003/06/02 01:16:10 jschauma Exp $
#
# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one.

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap-auth-cookie-1.9
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kciLink.com/pub/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	ftp://ftp.kciLink.com/pub/mod_auth_cookie.txt
COMMENT=	Cookie-based authentication for Apache

USE_BUILDLINK2=	YES

EXTRACT_CMD=	${DO_NADA}

APACHE_MODULE_NAME=	mod_auth_cookie.so

DIST_SUBDIR=	${PKGNAME}

post-extract:
	@(${ECHO} '#include "ap_compat.h"'; ${GZIP_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
