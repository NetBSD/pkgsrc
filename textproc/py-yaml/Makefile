# $NetBSD: Makefile,v 1.11 2012/10/25 06:56:53 asau Exp $
#

DISTNAME=	PyYAML-3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pyyaml.org/
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/distutils.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
