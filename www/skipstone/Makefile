# $NetBSD: Makefile,v 1.4 2002/01/25 00:19:51 rh Exp $
#

DISTNAME=	skipstone-0.7.8
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muhri.net/skipstone/
COMMENT=	Gtk+ web browser that embeds Mozilla's renderer

DEPENDS+=	mozilla>=0.9.7:../../www/mozilla

USE_GMAKE=	yes
USE_X11BASE=	yes

MAKE_ENV+=	X11PREFIX="${X11PREFIX}"

post-patch:
		${SED} -e s,@PREFIX@,${PREFIX},g \
			< ${WRKSRC}/src/skipstone > ${WRKSRC}/src/skipstone.tmp
		${MV} ${WRKSRC}/src/skipstone.tmp ${WRKSRC}/src/skipstone

.include "../../mk/bsd.pkg.mk"
