# $NetBSD: Makefile,v 1.5 2007/01/19 00:55:06 schmonz Exp $
#

DISTNAME=		html2text-2.25
PKGREVISION=		1
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
PYTHON_VERSIONS_ACCEPTED?=	24 23 22 21

INSTALLATION_DIRS=	share/html2text

do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TR} -d '\r' < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}		\
		> ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	cd ${WRKSRC};							\
	${INSTALL_SCRIPT} ${DISTNAME}${EXTRACT_SUFX}			\
		${PREFIX}/share/html2text/html2text.py

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
