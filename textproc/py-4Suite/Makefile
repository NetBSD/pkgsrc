# $NetBSD: Makefile,v 1.6 2012/10/25 06:56:47 asau Exp $
#

VER=		1.0.2
DISTNAME=	4Suite-XML-${VER}
PKGNAME=	${PYPKGPREFIX}-4Suite-${VER}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=foursuite/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://4suite.org/
COMMENT=	Open-source platform for XML and RDF processing
LICENSE=	apache-1.1

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

EGG_NAME=	${DISTNAME:S/-/_/}

SUBST_CLASSES+=		python
SUBST_FILES.python=	build/scripts.*/4xml
SUBST_FILES.python+=	build/scripts.*/4xpath
SUBST_FILES.python+=	build/scripts.*/4xslt
SUBST_FILES.python+=	build/scripts.*/4xupdate
SUBST_FILES.python+=	test/Xml/XPath/Borrowed/*.py
SUBST_FILES.python+=	test/Xml/XPath/Core/*.py
SUBST_FILES.python+=	test/test.py
SUBST_STAGE.python=	post-build
SUBST_SED.python=	-e 's,\#![^ ]* python,\#! ${PYTHONBIN},'

#PYTHON_SELF_CONFLICT=	yes

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config --prefix=${PREFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
