# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:37 jlam Exp $

DISTNAME=	Par152
PKGNAME=	par-1.52
CATEGORIES=	textproc
MASTER_SITES=	http://www.nicemice.net/par/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nicemice.net/par/
COMMENT=	Paragraph reformatter, vaguely similar to fmt, but better

BUILD_TARGET=
INSTALLATION_DIRS=	bin man/man1

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
