# $NetBSD: Makefile,v 1.5 2003/12/24 09:53:50 jmmv Exp $
#

DISTNAME=		PyQt-x11-gpl-3.8
PKGNAME=		${PYPKGPREFIX}-qt3-base-3.8
CATEGORIES=		x11
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/PyQt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/pyqt/
COMMENT=		Python binding for qt3

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
BUILDLINK_DEPENDS.qt3-tools=	qt3-tools>=3.1.2nb2

CONFIGURE_ARGS=		-q ${QTDIR} -m ${GMAKE} -p ${SIPBIN} -b ""

PYTHON_VERSIONS_ACCEPTED=	22pth 23pth 21pth
PY_PATCHPLIST=	yes
QTLIBDIR=	${QTDIR:S/${BUILDLINK_PREFIX.qt3-libs}\///}/lib
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX} QTLIBDIR=${QTLIBDIR}

MAKE_ENV+=	QTPREFIX=${QTDIR}

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build.py ${CONFIGURE_ARGS})

# XXX - hack. Shouldn't need the symlinks as qmake should let us build
# proper libraries that install outside of QTDIR more easily.
do-install:
	(cd ${WRKSRC}/qt && ${INSTALL_DATA} qt.py ${PREFIX}/${PYSITELIB})
	(cd ${WRKSRC}/qt && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
		libqtcmodule.la ${PREFIX}/${PYSITELIB})
	(cd ${PREFIX}/${PYSITELIB}; for i in libqtcmodule.*; do \
		${LN} -sf ${PREFIX}/${PYSITELIB}/$$i \
			${PREFIX}/${QTLIBDIR}/$$i; done)
	(cd ${WRKSRC}/pylupdate3 && ${INSTALL_PROGRAM} pylupdate \
		${PREFIX}/bin/pylupdate${PYVERSSUFFIX})
	(cd ${WRKSRC}/pyuic3 && ${INSTALL_PROGRAM} pyuic \
		${PREFIX}/bin/pyuic${PYVERSSUFFIX})

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-sip/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
