# $NetBSD: Makefile,v 1.11 2002/04/22 13:39:26 tron Exp $

DISTNAME=	skipstone-0.8.1
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muhri.net/skipstone/
COMMENT=	GTK+ web browser that embeds Mozilla's renderer

DEPENDS+=	mozilla>=0.9.9:../../www/mozilla

USE_GMAKE=	yes

MAKE_ENV+=	X11PREFIX="${X11PREFIX}"

post-patch:
		${SED} -e s,@PREFIX@,${X11PREFIX},g \
			< ${WRKSRC}/src/skipstone > ${WRKSRC}/src/skipstone.tmp
		${MV} ${WRKSRC}/src/skipstone.tmp ${WRKSRC}/src/skipstone

.include "../../mk/bsd.pkg.mk"
