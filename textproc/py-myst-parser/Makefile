# $NetBSD: Makefile,v 1.1 2024/01/22 16:28:16 adam Exp $

DISTNAME=	myst_parser-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/myst-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/MyST-Parser
COMMENT=	Extended CommonMark compliant parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=3.0:../../textproc/py-markdown-it-py
DEPENDS+=	${PYPKGPREFIX}-mdit-py-plugins>=0.4:../../textproc/py-mdit-py-plugins
DEPENDS+=	${PYPKGPREFIX}-sphinx>=6:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
.for bin in myst-anchors myst-docutils-demo myst-docutils-html myst-docutils-html5 \
	myst-docutils-latex myst-docutils-pseudoxml myst-docutils-xml myst-inv
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
