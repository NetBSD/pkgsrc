# $NetBSD: Makefile,v 1.6 1998/10/03 21:28:57 tv Exp $
#
# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one. 

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap-auth-cookie-1.6
NO_WRKSUBDIR=	yes
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kciLink.com/pub/
EXTRACT_SUFX=	.gz

MAINTAINER=	tv@netbsd.org

BUILD_DEPENDS+=	${PREFIX}/sbin/apxs:../../www/apache
RUN_DEPENDS+=	${PREFIX}/sbin/apxs:../../www/apache

USE_PERL5=	yes	# for "apxs"
EXTRACT_CMD=	${DO_NADA}

post-extract:
	@(${ECHO} '#include "compat.h"'; ${GZIP_CMD} -dc ${DISTDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c mod_auth_cookie.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_cookie.so

.include "../../mk/bsd.pkg.mk"
