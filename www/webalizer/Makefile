# $NetBSD: Makefile,v 1.10 2000/04/26 03:21:35 hubertf Exp $
#

DISTNAME=	webalizer-1.30-04-src
PKGNAME=	webalizer-1.30.04
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/webalizer/ \
		ftp://webalizer.dexa.org/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://www.mrunix.net/webalizer/

DEPENDS+=	gd-1.*:../../graphics/gd

WRKSRC=		${WRKDIR}/webalizer-1.30-04

USE_X11=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--with-gd=${LOCALBASE}/include

post-patch:
	@for f in webalizer.1; do \
		${SED} 's:@@prefix@@:'${PREFIX}':g' ${WRKSRC}/$$f \
			>${WRKSRC}/$$f.new && \
		${MV} ${WRKSRC}/$$f.new ${WRKSRC}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
