# $NetBSD: Makefile,v 1.14 1999/11/21 22:12:58 tron Exp $
#
# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one. 

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap-auth-cookie-1.7
NO_WRKSUBDIR=	yes
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kciLink.com/pub/
EXTRACT_SUFX=	.gz

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	ftp://ftp.kciLink.com/pub/mod_auth_cookie.txt

DEPENDS+=	apache-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

EXTRACT_CMD=	${DO_NADA}

post-extract:
	@(${ECHO} '#include "ap_compat.h"'; ${GZIP_CMD} -dc ${DISTDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c mod_auth_cookie.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_cookie.so

.include "../../mk/bsd.pkg.mk"
