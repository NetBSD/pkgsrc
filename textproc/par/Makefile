# $NetBSD: Makefile,v 1.9 2003/07/17 22:54:21 grant Exp $
# FreeBSD Id: Makefile,v 1.2 1997/08/13 06:33:51 asami Exp
#

DISTNAME=	Par152
PKGNAME=	par-1.52
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.berkeley.edu/~amc/Par/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.berkeley.edu/~amc/Par/
COMMENT=	Paragraph reformatter, vaguely similar to fmt, but better

ALL_TARGET=

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
