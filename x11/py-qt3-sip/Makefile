# $NetBSD: Makefile,v 1.14 2005/05/02 15:35:39 drochner Exp $
#

DISTNAME=	sip-4.2.1
PKGNAME=	${PYPKGPREFIX}-qt3-${DISTNAME}
CATEGORIES=	x11 devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/sip/index.php
COMMENT=	Tool to create Python bindings for C++ libraries

CONFLICTS+=	${PYPKGPREFIX}-qt2-sip-*

# needs qmake
BUILD_DEPENDS+=		qt3-tools-3.*:../../x11/qt3-tools

USE_X11=	yes
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++

CONFIGURE_ARGS=		-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-e ${PREFIX}/${PYINC}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fPIC
CONFIGURE_ARGS+=	LFLAGS_SHLIB=-shared

SUBST_CLASSES+=		pyversfx
SUBST_STAGE.pyversfx=	pre-configure
SUBST_FILES.pyversfx=	sipgen/sipgen.sbf
SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
