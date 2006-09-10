# $NetBSD: Makefile,v 1.42 2006/09/10 03:49:06 obache Exp $
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

EXTRACT_ONLY=	# empty

APACHE_MODULE_NAME=	mod_auth_cookie.so

DIST_SUBDIR=	${PKGNAME_NOREV}

do-extract:
	@(${ECHO} '#include "ap_compat.h"'; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}) \
		>${WRKSRC}/${DISTNAME}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
