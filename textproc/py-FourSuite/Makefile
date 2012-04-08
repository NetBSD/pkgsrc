# $NetBSD: Makefile,v 1.20 2012/04/08 19:09:12 wiz Exp $
#

DISTNAME=	4Suite-0.12.0a3
PKGNAME=	${PYPKGPREFIX}-FourSuite-0.12.0a3
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/old/4Suite/0.12.0/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://4suite.org/
COMMENT=	XML processing tools

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	${PYPKGPREFIX}-4Suite-*

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	25

REPLACE_PYTHON+=	Ft/Lib/DistExt/Tools/*.py
REPLACE_PYTHON+=	Ft/Ods/*.py
REPLACE_PYTHON+=	Ft/Ods/Parsers/Odl/*.py
REPLACE_PYTHON+=	Ft/Ods/Tools/*.py
REPLACE_PYTHON+=	Ft/Rdf/*.py
REPLACE_PYTHON+=	Ft/Server/ThirdParty/*.py
REPLACE_PYTHON+=	Ft/Server/Share/Data/*.py
REPLACE_PYTHON+=	Ft/ThirdParty/Xvif/*.py
REPLACE_PYTHON+=	Ft/Xml/*.py
REPLACE_PYTHON+=	Ft/Xml/*/*.py
REPLACE_PYTHON+=	test/test.py
REPLACE_PYTHON+=	test/Xml/XPath/*/*.py

#pyxml is needed at runtime to get pyexpat
#.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
