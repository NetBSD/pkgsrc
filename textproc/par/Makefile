# $NetBSD: Makefile,v 1.15 2007/01/07 09:14:13 rillig Exp $

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
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
