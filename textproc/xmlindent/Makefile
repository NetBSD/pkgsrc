# $NetBSD: Makefile,v 1.1.1.1 2004/04/01 05:29:57 xtraeme Exp $
#

DISTNAME=	xmlindent-0.2.16
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/
COMMENT=	XML stream reformatter written in ANSI C

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	lex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
