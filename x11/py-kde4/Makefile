# $NetBSD: Makefile,v 1.36 2014/01/01 11:52:43 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-kde4-${_KDE_VERSION}
DISTNAME=	pykde4-${_KDE_VERSION}
PKGREVISION=	3
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

.include "../../mk/bsd.prefs.mk"

# pid_t in the SunOS 32-bit environment is long, not int.
.if ${OPSYS} == "SunOS" && ${ABI} == "32"
SUBST_CLASSES+=		pid32
SUBST_STAGE.pid32=	pre-build
SUBST_FILES.pid32=	sip/kdecore/typedefs.sip
SUBST_FILES.pid32+=	sip/kdeui/kstartupinfo.sip
SUBST_SED.pid32=	-e '/QList.*int.*pids/s/int/pid_t/'
SUBST_SED.pid32+=	-e '/typedef.*int.*pid_t/s/int/long/'
.endif

#post-extract:
#	${CP} ${FILESDIR}/FindPolkitQt.cmake ${WRKSRC}/cmake/modules

# remove when file not patched any longer
#post-install:
#	${RM} -f ${DESTDIR}${PREFIX}/share/sip${PYVERSSUFFIX}/PyKDE4/kdecore/typedefs.sip.orig

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../security/polkit-qt/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
