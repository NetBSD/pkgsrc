# $NetBSD: Makefile,v 1.21 2001/09/09 20:36:52 agc Exp $
#
# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one. 

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap-auth-cookie-1.7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kciLink.com/pub/
EXTRACT_SUFX=	.gz

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	ftp://ftp.kciLink.com/pub/mod_auth_cookie.txt
COMMENT=	Cookie-based authentication for Apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

EXTRACT_CMD=	${DO_NADA}
WRKSRC=		${WRKDIR}

post-extract:
	@(${ECHO} '#include "ap_compat.h"'; ${GZIP_CMD} -dc ${DISTDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c mod_auth_cookie.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_cookie.so

.include "../../mk/bsd.pkg.mk"
