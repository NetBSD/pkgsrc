# $NetBSD: Makefile,v 1.7 2004/03/28 20:54:49 recht Exp $
#

DISTNAME=		PyQt-x11-gpl-3.8
PKGNAME=		${PYPKGPREFIX}-qt3-modules-3.8
CATEGORIES=		x11
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/PyQt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/pyqt/
COMMENT=		Python binding for qt3

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

CONFIGURE_ARGS=		-q ${QTDIR} -m ${GMAKE} -p ${SIPBIN}

PYTHON_VERSIONS_ACCEPTED=	22pth 23pth 21pth
PY_PATCHPLIST=	yes
QTLIBDIR=	${QTDIR:S/${BUILDLINK_PREFIX.qt3-libs}\///}/lib
PLIST_SUBST+=	QTLIBDIR=${QTLIBDIR}

MAKE_ENV+=	QTPREFIX=${QTDIR}

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build.py ${CONFIGURE_ARGS})

PYQTMODULES=	qtcanvas qtgl qtnetwork qtsql qttable qtui qtxml

# XXX - hack. Shouldn't need the symlinks as qmake should let us build
# proper libraries that install outside of QTDIR more easily.
do-install:
	(for f in ${PYQTMODULES}; do \
		(cd ${WRKSRC}/$${f} && ( \
			${INSTALL_DATA} $${f}.py ${PREFIX}/${PYSITELIB}; \
			${LIBTOOL} --mode=install ${INSTALL_DATA} \
				lib$${f}cmodule.la ${PREFIX}/${QTLIBDIR} \
			) \
		); \
	 done)
	(for f in ${PYQTMODULES}; do \
		(cd ${PREFIX}/${QTLIBDIR}; for i in lib$${f}cmodule.*; do \
			${LN} -sf ${PREFIX}/${QTLIBDIR}/$$i \
				${PREFIX}/${PYSITELIB}/$$i; done \
		); \
	done)

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
