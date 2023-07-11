# $NetBSD: Makefile,v 1.16 2023/07/11 05:46:30 nia Exp $
#

DISTNAME=	xmlindent-0.2.16
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.helsinki.fi/u/penberg/xmlindent/src/
COMMENT=	XML stream reformatter written in ANSI C
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex:run

GCC_REQD+=	3.0

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
