# $NetBSD: Makefile,v 1.10 2008/06/01 04:52:15 schmonz Exp $
#

DISTNAME=		html2text-2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text

WRKSRC=			${WRKDIR}

USE_TOOLS+=		tr
NO_BUILD=		yes
PYTHON_VERSIONS_ACCEPTED?=	25 24 23 21

INSTALLATION_DIRS=	share/html2text

do-extract:
	${RUN}								\
	${TR} -d '\r' < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}		\
		> ${WRKSRC}/html2text.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2text.py ${PREFIX}/share/html2text

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
