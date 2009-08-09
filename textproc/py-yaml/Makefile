# $NetBSD: Makefile,v 1.6 2009/08/09 09:37:00 wiz Exp $
#

DISTNAME=	PyYAML-3.08
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
CATEGORIES=	textproc python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pyyaml.org/
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
