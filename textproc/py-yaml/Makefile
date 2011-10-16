# $NetBSD: Makefile,v 1.7 2011/10/16 07:27:49 obache Exp $
#

DISTNAME=	PyYAML-3.08
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyYAML/yaml/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pyyaml.org/
COMMENT=	Collection of libraries to process YAML with Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/distutils.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
