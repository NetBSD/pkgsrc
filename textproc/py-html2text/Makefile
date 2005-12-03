# $NetBSD: Makefile,v 1.1.1.1 2005/12/03 00:47:04 schmonz Exp $
#

DISTNAME=		html2text-2.23
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.py

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text

WRKSRC=			${WRKDIR}

NO_BUILD=		yes
PYTHON_VERSIONS_ACCEPTED?=	24 23 22 21

INSTALLATION_DIRS=	share/html2text

do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-install:
	cd ${WRKSRC};							\
	${INSTALL_SCRIPT} ${DISTNAME}${EXTRACT_SUFX}			\
		${PREFIX}/share/html2text/html2text.py

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
