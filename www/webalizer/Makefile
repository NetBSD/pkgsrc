# $NetBSD: Makefile,v 1.14 2001/05/05 12:12:14 wiz Exp $
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
COMMENT=	Web server log file analysis program

DEPENDS+=	gd-1.*:../../graphics/gd
DEPENDS+=	freetype-lib>=1.3.1:../../graphics/freetype-lib

WRKSRC=		${WRKDIR}/webalizer-2.01-06

USE_X11=	yes
USE_XPM=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--with-gd=${LOCALBASE}/include \
		--enable-dns

post-patch:
	@for f in webalizer.1; do \
		${SED} 's:@@prefix@@:'${PREFIX}':g' ${WRKSRC}/$$f \
			>${WRKSRC}/$$f.new && \
		${MV} ${WRKSRC}/$$f.new ${WRKSRC}/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
