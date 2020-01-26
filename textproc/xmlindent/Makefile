# $NetBSD: Makefile,v 1.13 2020/01/26 17:32:19 rillig Exp $
#

DISTNAME=	xmlindent-0.2.16
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.helsinki.fi/u/penberg/xmlindent/src/
COMMENT=	XML stream reformatter written in ANSI C

USE_TOOLS+=	lex:run

GCC_REQD+=	3.0

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
