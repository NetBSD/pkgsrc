# $NetBSD: Makefile,v 1.6 2001/02/17 17:37:40 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1997/08/13 06:33:51 asami Exp
#

DISTNAME=       Par150
PKGNAME=        par-1.50
CATEGORIES=	textproc
MASTER_SITES=   http://www.cs.berkeley.edu/~amc/Par/

MAINTAINER=	mark@grondar.za
HOMEPAGE=	http://www.cs.berkeley.edu/~amc/Par/
COMMENT=	Pargraph reformatter for email

ALL_TARGET=

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
