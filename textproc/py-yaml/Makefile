# $NetBSD: Makefile,v 1.16 2016/09/01 17:01:46 wiz Exp $

DISTNAME=	PyYAML-3.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pyyaml.org/
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

.include "../../lang/python/distutils.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
