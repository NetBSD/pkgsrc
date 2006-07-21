# $NetBSD: Makefile,v 1.40 2006/07/21 16:24:37 wiz Exp $
#
# There are a few more mod_auth_cookie's out there doing slightly
# different things.  This one pkg would be a good place to dump them all in
# one.

DISTNAME=	mod_auth_cookie.c
PKGNAME=	ap13-auth-cookie-1.9
CATEGORIES=	www
MASTER_SITES=	http://raburton.lunarpages.com/apache/mod_auth_cookie/13/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://raburton.lunarpages.com/apache/mod_auth_cookie/
COMMENT=	Cookie-based authentication for Apache

CONFLICTS=	ap-auth-cookie-[0-9]*

WRKSRC=		${WRKDIR}

EXTRACT_CMD=	${DO_NADA}

APACHE_MODULE_NAME=	mod_auth_cookie.so

DIST_SUBDIR=	${PKGNAME_NOREV}

post-extract:
	@(${ECHO} '#include "ap_compat.h"'; ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
