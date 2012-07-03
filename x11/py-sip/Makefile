# $NetBSD: Makefile,v 1.33 2012/07/03 18:12:00 drochner Exp $

DISTNAME=	sip-4.13.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 devel python
MASTER_SITES=	http://www.riverbankcomputing.com/static/Downloads/sip4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.com/software/sip/intro
COMMENT=	Tool to create Python bindings for C++ libraries

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

CONFLICTS+=	${PYPKGPREFIX}-qt2-sip-* ${PYPKGPREFIX}-qt3-sip-*

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-e ${PREFIX}/${PYINC}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}
.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	-p freebsd-g++
.endif
CONFIGURE_ARGS+=	INCDIR=${PREFIX}/include
CONFIGURE_ARGS+=	LIBDIR=${PREFIX}/lib

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../mk/compiler.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fno-common
CONFIGURE_ARGS+=	LFLAGS_PLUGIN="-bundle -flat_namespace -undefined suppress"
.else
CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fPIC
CONFIGURE_ARGS+=	CXXFLAGS_SHLIB=-fPIC
.  if ${OPSYS} == "SunOS" && !empty(CC_VERSION:Mgcc*)
CONFIGURE_ARGS+=	-p solaris-g++
# gcc3 uses -mimpure-text to not pass -assert pure-text to the linker
CONFIGURE_ARGS+=	LFLAGS_SHLIB="-shared -mimpure-text"
.  else
CONFIGURE_ARGS+=	LFLAGS_SHLIB="-shared"
.  endif
.endif

# Hack: gcc on sparc64 miscompiles sipgen/parser.c at -O2
.if ${MACHINE_ARCH} == "sparc64" && !empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=	rm:-O2
.endif


SUBST_CLASSES+=		pyversfx
SUBST_STAGE.pyversfx=	pre-configure
SUBST_FILES.pyversfx=	sipgen/sipgen.sbf
SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
