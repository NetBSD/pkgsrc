# $NetBSD: Makefile,v 1.47 2016/08/28 15:48:35 wiz Exp $

DISTNAME=		html2text-2016.5.29
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=h/html2text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v2

REPLACE_PYTHON=	html2text/__init__.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/html2text ${DESTDIR}${PREFIX}/bin/html2text-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
