# $NetBSD: Makefile,v 1.1.1.1 2001/08/09 07:56:24 simonb Exp $
#

DISTNAME=	skipstone-0.7.4
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muhri.net/skipstone/
COMMENT=	Gtk+ web browser that embeds Mozilla's renderer

DEPENDS+=	mozilla>=0.9:../../www/mozilla

USE_GMAKE=	yes

post-patch:
		${SED} -e s,@PREFIX@,${PREFIX},g \
			< ${WRKSRC}/src/skipstone > ${WRKSRC}/src/skipstone.tmp
		${MV} ${WRKSRC}/src/skipstone.tmp ${WRKSRC}/src/skipstone

.include "../../mk/bsd.pkg.mk"
