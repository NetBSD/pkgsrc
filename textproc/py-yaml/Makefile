# $NetBSD: Makefile,v 1.24 2021/02/21 15:43:35 adam Exp $

DISTNAME=	PyYAML-5.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/yaml/pyyaml
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

.include "../../lang/python/egg.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
