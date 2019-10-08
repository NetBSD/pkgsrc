# $NetBSD: Makefile,v 1.1 2019/10/08 18:37:47 rhialto Exp $

DISTNAME=	html2text-2019.8.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html2text/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/Alir3z4/html2text
COMMENT=	Convert HTML into easy-to-read plain ASCII text
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
# This package is only for Python 2.7, because it is the last version
# of html2text to work with this Python version.
PYTHON_VERSIONS_ACCEPTED= 27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} html2text html2text-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
