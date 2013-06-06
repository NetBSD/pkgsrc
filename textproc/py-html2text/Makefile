# $NetBSD: Makefile,v 1.26 2013/06/06 01:52:01 schmonz Exp $
#

DISTNAME=		html2text-3.200.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://pypi.python.org/packages/source/h/html2text/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v2

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_SELF_CONFLICT=		yes

NO_BUILD=		yes

REPLACE_PYTHON=		html2text.py

INSTALLATION_DIRS=	share/html2text

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2text.py ${DESTDIR}${PREFIX}/share/html2text

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
