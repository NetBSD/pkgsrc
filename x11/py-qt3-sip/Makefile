# $NetBSD: Makefile,v 1.3 2003/08/19 04:35:05 jmc Exp $
#

DISTNAME=	sip-x11-gpl-3.7
PKGNAME=	${PYPKGPREFIX}-qt3-sip-3.7
PKGREVISION=	1
CATEGORIES=	x11 devel
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/sip/index.php
COMMENT=	Tool to create Python bindings for C++ libraries

CONFLICTS+=	${PYPKGPREFIX}-qt2-sip-*

# needs qmake
BUILD_DEPENDS+=		qt3-tools-3.*:../../x11/qt3-tools

USE_BUILDLINK2= 	# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
USE_GMAKE=	yes

CONFIGURE_ARGS=		-q ${QTDIR} -m ${GMAKE}

PYQT_TMPDIR=		${WRKDIR}/pyqt_tmp
CONFIGURE_ARGS+=	-d ${PYQT_TMPDIR}
CONFIGURE_ARGS+=	-b ${PYQT_TMPDIR}

PYTHON_VERSIONS_ACCEPTED=	22pth 21pth
PY_PATCHPLIST=	yes
QTLIBDIR=	${QTDIR:S/${BUILDLINK_PREFIX.qt3-libs}\///}/lib
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX} QTLIBDIR=${QTLIBDIR}

MAKE_ENV+=	QTPREFIX=${QTDIR}

do-configure:
	${MKDIR} -p ${PYQT_TMPDIR}
	(cd ${WRKSRC} && ${PYTHONBIN} build.py ${CONFIGURE_ARGS})

# XXX - hack. Shouldn't need the symlinks as qmake should let us build
# proper libraries that install outside of QTDIR more easily.
post-install:
	(cd ${PYQT_TMPDIR} && ${INSTALL_PROGRAM} sip \
		${PREFIX}/bin/sip${PYVERSSUFFIX})
	(cd ${PYQT_TMPDIR} && ${LIBTOOL} ${INSTALL_DATA} \
		libsip.la ${PREFIX}/${PYSITELIB})
	(cd ${PREFIX}/${PYSITELIB}; for i in libsip.*; do \
		${LN} -sf ${PREFIX}/${PYSITELIB}/$$i \
			${PREFIX}/${QTLIBDIR}/$$i; done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../x11/qt3-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
