# $NetBSD: Makefile,v 1.15.2.2 2002/08/25 21:22:15 jlam Exp $
#

DISTNAME=	bozohttpd-5.14
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	bozotic HTTP server; small and secure

BUILD_DEFS+=	USE_INET6

USE_BUILDLINK2=	YES

MAKE_ENV+=	BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/man

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif

pre-patch:
	${MV} -f ${WRKSRC}/bozohttpd.8 ${WRKSRC}/bozohttpd.8.in

post-patch:
	${SED}	-e "s,@PREFIX@,${PREFIX},g"				\
		${WRKSRC}/bozohttpd.8.in > ${WRKSRC}/bozohttpd.8

.include "../../mk/bsd.pkg.mk"
