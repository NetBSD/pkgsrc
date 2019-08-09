# $NetBSD: Makefile,v 1.20 2019/08/09 07:46:30 adam Exp $

DISTNAME=	PyYAML-5.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/yaml/pyyaml
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

.include "../../lang/python/distutils.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
