# $NetBSD: Makefile,v 1.24 2002/09/09 17:13:32 jlam Exp $
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

post-build:
	cd ${WRKSRC}; for file in bozohttpd.8; do			\
		${SED}	-e "s|/usr/pkg/|${PREFIX}/|g"			\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
