# $NetBSD: Makefile,v 1.3 2022/01/05 20:47:37 wiz Exp $

DISTNAME=	html2text-2019.8.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} html2text html2text-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
