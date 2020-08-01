# $NetBSD: Makefile,v 1.92 2020/08/01 07:18:35 tnn Exp $

DISTNAME=	PyQt4_gpl_${PYQT_SYS}-4.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyQt4_gpl_${PYQT_SYS}/qt4/}
PKGREVISION=	4
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt4
HOMEPAGE=	https://riverbankcomputing.com/software/pyqt/intro
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sip-qt4>=4.19.23:../../x11/py-sip-qt4

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	--sipdir ${PREFIX}/share/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	-q ${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	--confirm-license
CONFIGURE_ARGS+=	--qsci-api
CONFIGURE_ARGS+=	--verbose

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

PY_PATCHPLIST=		yes

BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtCore
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtDeclarative
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtDesigner
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtGui
BUILDLINK_TRANSFORM+=	rm:-Wl,-R${WRKSRC}/qpy/QtOpenGL
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtCore
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtDeclarative
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtDesigner
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtGui
BUILDLINK_TRANSFORM+=	rm:-Wl,-rpath,${WRKSRC}/qpy/QtOpenGL

# This is a hack. CPPFLAGS and CXXFLAGS from the environment are ignored,
# however, so I don't know a better way to fix it.
SUBST_CLASSES+=		PIC
SUBST_STAGE.PIC=	post-configure
SUBST_FILES.PIC=	qpy/QtCore/Makefile qpy/QtGui/Makefile
SUBST_SED.PIC=		-e "s/CXXFLAGS      =/CXXFLAGS      = -fPIC/"
SUBST_MESSAGE.PIC=	Adding -fPIC to CXXFLAGS.

#SUBST_CLASSES+=	pyversfx
#SUBST_STAGE.pyversfx=	pre-configure
#SUBST_FILES.pyversfx=	pyuic4/pyuic.sbf pylupdate4/pylupdate.sbf
#SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "Darwin"
PYQT_SYS=	mac
.else
PYQT_SYS=	x11
.endif

.if make(distinfo) || make (makesum) || make(mdi)
DISTFILES+=	PyQt4_gpl_mac-${PKGVERSION_NOREV}${EXTRACT_SUFX}
DISTFILES+=	PyQt4_gpl_x11-${PKGVERSION_NOREV}${EXTRACT_SUFX}
.endif

.include "../../lang/python/extension.mk"

# configure-ng.py has Darwin specific code to avoid using sys.executable
# that assumes the builtin python when configuring the path in pyuic/pyuic4.
# Instead of patching that out, just do a manual replace-interpreter
# on the configured result
SUBST_CLASSES.Darwin+=		fix-pyuic4
SUBST_STAGE.fix-pyuic4=		post-configure
SUBST_MESSAGE.fix-pyuic4=	Fixing python interpreter path in pyuic4
SUBST_FILES.fix-pyuic4=		pyuic/pyuic4
SUBST_SED.fix-pyuic4=		-e 's,python[^ ]*,${PYTHONBIN},'

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.if !empty(PYVERSSUFFIX:M2*)
UIC_PORT_REMOVE=	port_v3
.endif
.if !empty(PYVERSSUFFIX:M3*)
UIC_PORT_REMOVE=	port_v2
.endif

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4/uic/${UIC_PORT_REMOVE}
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4

.include "../../x11/py-sip/buildlink3.mk"
# needs the QtXmlPatterns fix
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.6.1nb3
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.4.0nb1
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
