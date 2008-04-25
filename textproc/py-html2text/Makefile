# $NetBSD: Makefile,v 1.8 2008/04/25 20:39:13 joerg Exp $
#

DISTNAME=		html2text-2.29
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
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TR} -d '\r' < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}		\
		> ${WRKSRC}/html2text.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2text.py ${PREFIX}/share/html2text

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
