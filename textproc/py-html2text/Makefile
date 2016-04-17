# $NetBSD: Makefile,v 1.44 2016/04/17 10:01:18 wiz Exp $

DISTNAME=		html2text-2016.4.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		http://pypi.python.org/packages/source/h/html2text/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v2

REPLACE_PYTHON=	html2text/__init__.py
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/html2text ${DESTDIR}${PREFIX}/bin/html2text-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
