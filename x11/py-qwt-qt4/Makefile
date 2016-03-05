# $NetBSD: Makefile,v 1.6 2016/03/05 11:29:47 jperkin Exp $

DISTNAME=	PyQwt-5.2.0
PKGNAME=	${PYPKGPREFIX}-qwt-qt4-${DISTNAME:S/PyQwt-//}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqwt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyqwt.sourceforge.net/
COMMENT=	Python bindings for the Qwt QT4 C++ class library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
BUILD_DIRS=	configure

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# Following line rescues from 'Unresolved dependency with pbulk'
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-Numeric

REPLACE_PYTHON+=qt4lib/PyQt4/Qwt5/grace.py
REPLACE_PYTHON+=qt4lib/PyQt4/Qwt5/qplt.py

do-configure:
	(cd ${WRKSRC}/configure &&\
	 ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${PYTHONBIN}\
	 configure.py -Q ../qwt-5.2)

.include "../../lang/python/application.mk"

.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"

.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qwt-qt4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
