# $NetBSD: Makefile,v 1.4 2000/08/23 12:24:41 jlam Exp $
#

DISTNAME=	bozohttpd-5.05
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
		
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && (${USE_INET6} == "YES")
CPPFLAGS+=	-DINET6
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
