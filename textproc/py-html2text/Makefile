# $NetBSD: Makefile,v 1.20 2011/06/09 06:21:38 schmonz Exp $
#

DISTNAME=		aaronsw-${GHNAME}-${GHVERSION}-0-g${GHCOMMIT}
GHNAME=			html2text
GHVERSION=		3.02
GHCOMMIT=		d9bf7d6
PKGNAME=		${PYPKGPREFIX}-${GHNAME}-${GHVERSION}
CATEGORIES=		textproc python
MASTER_SITES=		http://download.github.com/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/aaronsw-${GHNAME}-${GHCOMMIT}

NO_BUILD=		yes

REPLACE_PYTHON=		html2text.py

INSTALLATION_DIRS=	share/html2text

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2text.py ${DESTDIR}${PREFIX}/share/html2text

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
