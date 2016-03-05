# $NetBSD: Makefile,v 1.43 2016/03/05 11:27:59 jperkin Exp $

PKGREVISION= 1
.include "../../x11/qt4-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt4-${DISTNAME:tl:S/-gpl-/-/}
COMMENT=	QScintilla -- Python bindings

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

MAKE_FLAGS+=		TARGET=Qsci.la TARGETD=Qsci.la TARGETL=Qsci.la
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}
LIBS+=			-lqscintilla2
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}\ ${LIBS:Q}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} configure.py \
	    --qmake=${QTDIR}/bin/qmake --sip=${PREFIX}/bin/sip${PYVERSSUFFIX} \
	    --pyqt-sipdir=${PREFIX}/share/sip${PYVERSSUFFIX} \
	    --qsci-sipdir=${PREFIX}/share/sip${PYVERSSUFFIX} \
	    --qsci-libdir=${QTDIR}/lib

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/Qsci.la \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt4/

.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-qscintilla+=	qt4-qscintilla>=${PKGVERSION_NOREV}
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
