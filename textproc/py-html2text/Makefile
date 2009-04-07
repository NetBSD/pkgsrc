# $NetBSD: Makefile,v 1.15 2009/04/07 04:43:23 schmonz Exp $
#

DISTNAME=		html2text-2.35
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

USE_TOOLS+=		tr
NO_BUILD=		yes

INSTALLATION_DIRS=	share/html2text

do-extract:
	${RUN}								\
	${TR} -d '\r' < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}		\
		> ${WRKSRC}/html2text.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2text.py ${DESTDIR}${PREFIX}/share/html2text

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
