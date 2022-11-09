# $NetBSD: Makefile,v 1.27 2022/11/09 13:14:17 joerg Exp $

DISTNAME=	PyYAML-5.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyYAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaml/pyyaml
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

.include "../../lang/python/egg.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
