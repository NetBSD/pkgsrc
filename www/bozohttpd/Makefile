# $NetBSD: Makefile,v 1.15.2.1 2002/06/21 23:05:47 jlam Exp $
#

DISTNAME=	bozohttpd-5.09
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	bozotic HTTP server; small and secure

BUILD_DEFS+=	USE_INET6

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && (${USE_INET6} == "YES")
CPPFLAGS+=	-DINET6
.endif

pre-patch:
	${MV} -f ${WRKSRC}/bozohttpd.8 ${WRKSRC}/bozohttpd.8.in

post-patch:
	${SED}	-e "s,@PREFIX@,${PREFIX},g"				\
		${WRKSRC}/bozohttpd.8.in > ${WRKSRC}/bozohttpd.8

.include "../../mk/bsd.pkg.mk"
