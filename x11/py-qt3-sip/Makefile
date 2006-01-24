# $NetBSD: Makefile,v 1.26 2006/01/24 07:32:59 wiz Exp $
#

DISTNAME=	sip-4.3.2
PKGNAME=	${PYPKGPREFIX}-qt3-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11 devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/sip/index.php
COMMENT=	Tool to create Python bindings for C++ libraries

CONFLICTS+=	${PYPKGPREFIX}-qt2-sip-*

# needs qmake
BUILD_DEPENDS+=		qt3-tools-3.*:../../x11/qt3-tools

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-e ${PREFIX}/${PYINC}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fno-common
CONFIGURE_ARGS+=	LFLAGS_PLUGIN="-bundle -flat_namespace -undefined suppress"
.else
CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fPIC
.if ${OPSYS} == "SunOS" && !empty(CC_VERSION:Mgcc*)
# gcc3 uses -mimpure-text to not pass -assert pure-text to the linker
CONFIGURE_ARGS+=        LFLAGS_SHLIB="-shared -mimpure-text"
.else
CONFIGURE_ARGS+=       LFLAGS_SHLIB="-shared"
.endif
.endif

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
