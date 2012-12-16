# $NetBSD: Makefile,v 1.19 2012/12/16 01:52:40 obache Exp $

PKGNAME=	${PYPKGPREFIX}-kde4-${_KDE_VERSION}
DISTNAME=	pykde4-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	misc
COMMENT=	Python bindings for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

REPLACE_PYTHON+= \
	tools/pykdeuic4/*.py \
	examples/*.py \
	examples/*/*.py \
	docs/html/tutorials/started/*.py

# We need to replace the embedded interpreter
SUBST_CLASSES+=	pykdeuic4
SUBST_STAGE.pykdeuic4=	post-build
SUBST_FILES.pykdeuic4=	tools/pykdeuic4/pykdeuic4.py
SUBST_SED.pykdeuic4=	-e 's:/usr/bin/env python$$:${PYTHONBIN}:'

#post-extract:
#	${CP} ${FILESDIR}/FindPolkitQt.cmake ${WRKSRC}/cmake/modules

# remove when file not patched any longer
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/sip${PYVERSSUFFIX}/PyKDE4/kdecore/typedefs.sip.orig

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/polkit-qt/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-sip+=	${PYPKGPREFIX}-sip>=4.10
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
