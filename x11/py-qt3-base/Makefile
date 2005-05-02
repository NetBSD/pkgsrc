# $NetBSD: Makefile,v 1.14 2005/05/02 15:36:53 drochner Exp $
#

DISTNAME=		PyQt-x11-gpl-3.14.1
PKGNAME=		${PYPKGPREFIX}-qt3-base-3.14.1
CATEGORIES=		x11 python
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/PyQt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/pyqt/
COMMENT=		Python binding for qt3

USE_X11=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
BUILDLINK_DEPENDS.qt3-tools=	qt3-tools>=3.1.2nb2

CONFIGURE_ARGS=		-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

SUBST_CLASSES+=		pyversfx
SUBST_STAGE.pyversfx=	pre-configure
SUBST_FILES.pyversfx=	pyuic3/pyuic.sbf pylupdate3/pylupdate.sbf
SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS})

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-sip/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
