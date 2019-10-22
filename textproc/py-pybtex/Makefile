# $NetBSD: Makefile,v 1.5 2019/10/22 06:37:36 adam Exp $

DISTNAME=	pybtex-0.22.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://pybtex.org/
COMMENT=	BibTeX-compatible bibliography processor written in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-latexcodec>=1.0.4:../../print/py-latexcodec
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.01:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybtex pybtex-${PYVERSSUFFIX} && \
	${MV} pybtex-convert pybtex-convert-${PYVERSSUFFIX} && \
	${MV} pybtex-format pybtex-format-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
