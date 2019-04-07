# $NetBSD: Makefile,v 1.18 2019/04/07 22:02:09 adam Exp $

DISTNAME=	PyYAML-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://pyyaml.org/wiki/PyYAML
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

.include "../../lang/python/distutils.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
