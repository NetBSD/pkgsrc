# $NetBSD: Makefile,v 1.1 1998/06/04 20:41:09 tv Exp $
#

# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one. 

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap-auth-cookie
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kciLink.com/pub/
EXTRACT_CMD=	${DO_NADA}
EXTRACT_SUFX=	.gz

MAINTAINER=	tv@netbsd.org

DEPENDS+=	apache-1.3b7:../apache
USE_PERL5=	yes	# for "apxs"

post-extract:
	@(${ECHO} '#include "compat.h"'; ${GZIP_CMD} -dc ${DISTDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c mod_auth_cookie.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_cookie.so
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
