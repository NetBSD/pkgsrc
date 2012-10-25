# $NetBSD: Makefile,v 1.17 2012/10/25 06:56:44 asau Exp $

DISTNAME=	Par152
PKGNAME=	par-1.52
CATEGORIES=	textproc
MASTER_SITES=	http://www.nicemice.net/par/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nicemice.net/par/
COMMENT=	Paragraph reformatter, vaguely similar to fmt, but better

BUILD_TARGET=
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
