# $NetBSD: Makefile,v 1.12 2025/07/22 07:12:07 adam Exp $

DISTNAME=	pybtex-0.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://pybtex.org/
COMMENT=	BibTeX-compatible bibliography processor written in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-latexcodec>=1.0.4:../../print/py-latexcodec
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.01:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybtex pybtex-${PYVERSSUFFIX} && \
	${MV} pybtex-convert pybtex-convert-${PYVERSSUFFIX} && \
	${MV} pybtex-format pybtex-format-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
