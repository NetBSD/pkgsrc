# $NetBSD: Makefile,v 1.11 2000/10/18 16:41:23 mjl Exp $
#

DISTNAME=	webalizer-2.01-06-src
PKGNAME=	webalizer-2.01.06
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/webalizer/ \
		ftp://webalizer.dexa.org/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://www.mrunix.net/webalizer/

DEPENDS+=	gd-1.*:../../graphics/gd

WRKSRC=		${WRKDIR}/webalizer-2.01-06

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
