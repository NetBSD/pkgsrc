# $NetBSD: Makefile,v 1.2 2023/04/13 13:52:40 wiz Exp $

DISTNAME=	yamlordereddictloader-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yamlordereddictloader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fmenabe/python-yamlordereddictloader/
COMMENT=	Module providing ordered loading and dumping of PyYAML
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
