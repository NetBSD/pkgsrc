# $NetBSD: Makefile,v 1.3 1999/03/30 22:41:41 mjl Exp $
#

DISTNAME=	webalizer-1.22-01-src
PKGNAME=	webalizer-1.22.01
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://www.mrunix.net/webalizer/

DEPENDS=	gd-1.3:../../graphics/gd

WRKSRC	= ${WRKDIR}/webalizer-1.22-01

post-patch:
	@for f in webalizer.c webalizer.1; do \
	${SED} 's:@@prefix@@:'${PREFIX}':g' ${WRKSRC}/$$f >${WRKSRC}/$$f.new && \
		 ${MV} ${WRKSRC}/$$f.new ${WRKSRC}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
