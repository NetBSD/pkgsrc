# $NetBSD: Makefile,v 1.27 2016/01/15 14:24:41 darcy Exp $

DISTNAME=	Sphinx-1.3.4
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
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

REPLACE_PYTHON+=	sphinx/pycode/pgen2/token.py

#USE_TOOLS+=	makeinfo
# also needs LaTeX with additional packages (tex-mdwtools, tex-parskip)
#do-test:
#	cd ${WRKSRC}/tests && ${PYTHONBIN} run.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-apidoc ${DESTDIR}${PREFIX}/bin/sphinx-apidoc${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-autogen ${DESTDIR}${PREFIX}/bin/sphinx-autogen${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-build ${DESTDIR}${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-quickstart ${DESTDIR}${PREFIX}/bin/sphinx-quickstart${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
