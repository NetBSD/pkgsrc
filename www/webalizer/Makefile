# $NetBSD: Makefile,v 1.1.1.1 1998/11/07 13:22:53 frueauf Exp $
#

DISTNAME=	webalizer-1.20-07-src
PKGNAME=	webalizer-1.20-07
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://samhain.unix.cslab.tuwien.ac.at/pub/webalizer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://www.mrunix.net/webalizer/

DEPENDS=	gd-1.3:../../graphics/gd

NO_WRKSUBDIR=	yes

post-patch:
	@for f in webalizer.c webalizer.1; do \
	${SED} 's:@@prefix@@:'${PREFIX}':g' ${WRKDIR}/$$f >${WRKDIR}/$$f.new && \
		 ${MV} ${WRKDIR}/$$f.new ${WRKDIR}/$$f; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webalizer ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/sample.conf ${PREFIX}/etc/webalizer.conf-sample

.include "../../mk/bsd.pkg.mk"
