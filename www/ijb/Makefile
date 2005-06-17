# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:40 jlam Exp $
#

DISTNAME=	ijb20
PKGNAME=	ijb-2.0.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.junkbuster.com/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.junkbuster.com/
COMMENT=	The Internet Junkbuster Proxy blocks unwanted banner ads and cookies

MAKE_ENV+=	MORE_CFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/junkbuster.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/junkbuster
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini \
		${PREFIX}/share/examples/junkbuster/junkbuster.ini
.for f in saclfile sblock scookie sforward strust
	${INSTALL_DATA} ${WRKSRC}/${f}.ini \
		${PREFIX}/share/examples/junkbuster/${f}.ini
.endfor

.include "../../mk/bsd.pkg.mk"
