# $NetBSD: Makefile,v 1.14 2002/04/23 11:23:58 zuntum Exp $
#

DISTNAME=	bozohttpd-5.09
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	bozotic HTTP server; small and secure

BUILD_DEFS+=	USE_INET6

USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && (${USE_INET6} == "YES")
CPPFLAGS+=	-DINET6
.endif

CFLAGS+=	-DDEBUG=1
pre-patch:
	${MV} ${WRKSRC}/bozohttpd.8 ${WRKSRC}/bozohttpd.8.in

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX},g" <${WRKSRC}/bozohttpd.8.in \
	    >${WRKSRC}/bozohttpd.8

.include "../../mk/bsd.pkg.mk"
