# $NetBSD: Makefile,v 1.4 1999/04/09 20:19:11 mjl Exp $
#

DISTNAME=	webalizer-1.22-03-src
PKGNAME=	webalizer-1.22.03
CATEGORIES=	www
MASTER_SITES=	\
	ftp://ftp.mrunix.net/pub/webalizer/ \
	ftp://samhain.unix.cslab.tuwien.ac.at/pub/webalizer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://www.mrunix.net/webalizer/

DEPENDS=	gd-1.3:../../graphics/gd

WRKSRC	= ${WRKDIR}/webalizer-1.22-03

post-patch:
	@for f in webalizer.c webalizer.1; do \
	${SED} 's:@@prefix@@:'${PREFIX}':g' ${WRKSRC}/$$f >${WRKSRC}/$$f.new && \
		 ${MV} ${WRKSRC}/$$f.new ${WRKSRC}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
