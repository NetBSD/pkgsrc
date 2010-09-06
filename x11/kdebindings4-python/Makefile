# $NetBSD: Makefile,v 1.17 2010/09/06 12:22:51 wiz Exp $

PKGNAME=	kdebindings4-python-${_KDE_VERSION}
DISTNAME=	kdebindings-${_KDE_VERSION}
PKGREVISION=	2
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

REPLACE_PYTHON+= \
	python/pykde4/examples/polkitqtExamples/pkexample.py \
	python/pykde4/examples/polkitqtExamples/pkexamplehelper.py \
	python/pykde4/examples/solid_demo.py

post-extract:
	${CP} ${FILESDIR}/FindPolkitQt.cmake ${WRKSRC}/cmake/modules

# patched by pkgsrc; remove them, otherwise they get installed
post-patch:
	rm ${WRKSRC}/python/pykde4/sip/akonadi/addressattribute.sip.orig
	rm ${WRKSRC}/python/pykde4/sip/kdecore/typedefs.sip.orig

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
