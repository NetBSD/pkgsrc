# $NetBSD: Makefile,v 1.4 1998/06/22 13:12:14 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/08/13 06:33:51 asami Exp
#

DISTNAME=       Par150
PKGNAME=        par-1.50
CATEGORIES=	textproc
MASTER_SITES=   http://www.cs.berkeley.edu/~amc/Par/

MAINTAINER=	mark@grondar.za

ALL_TARGET=

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
