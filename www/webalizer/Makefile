# $NetBSD: Makefile,v 1.7 1999/08/27 09:06:37 agc Exp $
#

DISTNAME=	webalizer-1.30-04-src
PKGNAME=	webalizer-1.30.04
CATEGORIES=	www
MASTER_SITES=	ftp://www.mrunix.net/webalizer/ \
		ftp://webalizer.dexa.org/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://www.mrunix.net/webalizer/

DEPENDS=	gd-1.6.3:../../graphics/gd

WRKSRC=		${WRKDIR}/webalizer-1.30-04

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --with-gdlib=${PREFIX}/lib \
		--with-gd=${PREFIX}/include/gd

post-patch:
	@for f in webalizer.1; do \
	${SED} 's:@@prefix@@:'${PREFIX}':g' ${WRKSRC}/$$f >${WRKSRC}/$$f.new && \
		 ${MV} ${WRKSRC}/$$f.new ${WRKSRC}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
