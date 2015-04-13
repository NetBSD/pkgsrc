# $NetBSD: Makefile,v 1.5 2015/04/13 23:12:44 rodent Exp $

DISTNAME=	Pmw_2_0_0-rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/_/./g:S/-rc/rc/}
EGG_NAME=	Pmw-2.0.0
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	Python meta widgets (python-3.x version)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	blt>=2.4i:../../x11/blt

WRKSRC=		${WRKDIR}/Pmw2

USE_LANGUAGES=	# empty

REPLACE_PYTHON=		Pmw/Pmw_2_0_0/bin/bundlepmw.py
REPLACE_PYTHON+=	Pmw/Pmw_2_0_0/demos/All.py
REPLACE_PYTHON+=	Pmw/Pmw_2_0_0/tests/All.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
