# $NetBSD: Makefile,v 1.8 2022/01/10 08:04:09 wiz Exp $

DISTNAME=	Pmw_2_0_0-rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/_/./g:S/-rc/rc/}
PKGREVISION=	1
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
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
