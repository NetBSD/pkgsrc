# $NetBSD: Makefile,v 1.17 2023/07/17 22:00:25 nia Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
