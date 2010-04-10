# $NetBSD: Makefile,v 1.11 2010/04/10 02:45:05 markd Exp $

PKGNAME=	kdebindings4-python-${_KDE_VERSION}
DISTNAME=	kdebindings-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Python bindings for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_smoke=OFF -DBUILD_ruby=OFF -DBUILD_php=OFF 
CMAKE_ARGS+=	-DBUILD_java=OFF -DBUILD_falcon=OFF -DBUILD_csharp=OFF
CMAKE_ARGS+=	-DENABLE_SMOKE=off
CMAKE_ARGS+=	-DENABLE_QYOTO=off
CMAKE_ARGS+=	-DENABLE_QTRUBY=off -DENABLE_KORUNDUM=off
CMAKE_ARGS+=	-DENABLE_KROSSRUBY=off
CMAKE_ARGS+=	-DENABLE_KROSSJAVA=off -DENABLE_KROSSFALCON=off
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	26 25
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	${CP} ${FILESDIR}/FindPolkitQt.cmake ${WRKSRC}/cmake/modules

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/polkit-qt/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-sip+=  ${PYPKGPREFIX}-sip>=4.10
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
