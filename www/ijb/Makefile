# $NetBSD: Makefile,v 1.9 2009/02/13 21:38:17 abs Exp $
#

DISTNAME=	ijb20
PKGNAME=	ijb-2.0.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.junkbuster.com/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.junkbuster.com/
COMMENT=	Internet Junkbuster Proxy to block banner ads and cookies

MAKE_ENV+=	MORE_CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/junkbuster
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/junkbuster.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini \
		${DESTDIR}${PREFIX}/share/examples/junkbuster/junkbuster.ini
.for f in saclfile sblock scookie sforward strust
	${INSTALL_DATA} ${WRKSRC}/${f}.ini \
		${DESTDIR}${PREFIX}/share/examples/junkbuster/${f}.ini
.endfor

.include "../../mk/bsd.pkg.mk"
