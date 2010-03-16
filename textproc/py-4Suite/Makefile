# $NetBSD: Makefile,v 1.1.1.1 2010/03/16 22:31:04 pettai Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

SUBST_CLASSES+=		python
SUBST_FILES.python=	${WRKSRC}/build/scripts.*/4xml
SUBST_FILES.python+=	${WRKSRC}/build/scripts.*/4xpath
SUBST_FILES.python+=	${WRKSRC}/build/scripts.*/4xslt
SUBST_FILES.python+=	${WRKSRC}/build/scripts.*/4xupdate
SUBST_STAGE.python=	post-build
SUBST_SED.python=	-e 's,\#![^ ]* python,\#! ${PYTHONBIN},'

# lang/python/egg.mk can't be used because of setup.py
# Use this quirk instead for the egg file
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config --prefix=${PREFIX}


.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
