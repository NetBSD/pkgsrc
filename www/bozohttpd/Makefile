# $NetBSD: Makefile,v 1.5 2000/08/27 09:04:31 itojun Exp $
#

DISTNAME=	bozohttpd-5.06
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
		
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && (${USE_INET6} == "YES")
CPPFLAGS+=	-DINET6
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
