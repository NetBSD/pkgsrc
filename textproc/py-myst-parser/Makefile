# $NetBSD: Makefile,v 1.7 2025/02/23 21:15:52 wiz Exp $

DISTNAME=	myst_parser-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/myst-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/MyST-Parser
COMMENT=	Extended CommonMark compliant parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.19:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=3.0:../../textproc/py-markdown-it-py
DEPENDS+=	${PYPKGPREFIX}-mdit-py-plugins>=0.4.1:../../textproc/py-mdit-py-plugins
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

post-install:
.for bin in myst-anchors myst-docutils-demo myst-docutils-html myst-docutils-html5 \
	myst-docutils-latex myst-docutils-pseudoxml myst-docutils-xml myst-inv
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
