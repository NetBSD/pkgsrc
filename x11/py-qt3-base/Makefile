# $NetBSD: Makefile,v 1.1.1.1 2003/07/22 17:22:48 drochner Exp $
#

DISTNAME=		PyQt-x11-gpl-3.7
PKGNAME=		${PYPKGPREFIX}-qt3-base-3.7
CATEGORIES=		x11
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/PyQt/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/pyqt/
COMMENT=		Python binding for qt3

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
BUILDLINK_DEPENDS.qt3-tools=	qt3-tools>=3.1.2nb2

CONFIGURE_ARGS=		-q ${QTDIR} -m ${GMAKE} -p ${SIPBIN} -b ""

PYTHON_VERSIONS_ACCEPTED=	22pth 21pth
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

MAKE_ENV+=	QTPREFIX=${QTDIR}

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build.py ${CONFIGURE_ARGS})

do-install:
	(cd ${WRKSRC}/qt && ${INSTALL_DATA} qt.py ${PREFIX}/${PYSITELIB})
	(cd ${WRKSRC}/qt && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
		libqtcmodule.la ${PREFIX}/${PYSITELIB})
	(cd ${WRKSRC}/pylupdate3 && ${INSTALL_PROGRAM} pylupdate \
		${PREFIX}/bin/pylupdate${PYVERSSUFFIX})
	(cd ${WRKSRC}/pyuic3 && ${INSTALL_PROGRAM} pyuic \
		${PREFIX}/bin/pyuic${PYVERSSUFFIX})

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-sip/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
