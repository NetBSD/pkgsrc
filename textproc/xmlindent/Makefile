# $NetBSD: Makefile,v 1.3 2004/06/28 00:28:07 kristerw Exp $
#

DISTNAME=	xmlindent-0.2.16
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/
COMMENT=	XML stream reformatter written in ANSI C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	lex

GCC_REQD=	3.0

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
