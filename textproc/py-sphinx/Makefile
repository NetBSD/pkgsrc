# $NetBSD: Makefile,v 1.23 2014/01/27 19:14:26 wiz Exp $

DISTNAME=	Sphinx-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sphinx/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	sphinx/pycode/pgen2/token.py

#USE_TOOLS+=	makeinfo
# also needs LaTeX with additional packages (tex-mdwtools, tex-parskip)
#do-test:
#	cd ${WRKSRC}/tests && ${PYTHONBIN} run.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
