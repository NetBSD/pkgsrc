# $NetBSD: Makefile,v 1.1.1.1 2002/08/20 14:09:45 drochner Exp $
#

DISTNAME=	4Suite-0.12.0a2
PKGNAME=	${PYPKGPREFIX}-4Suite-0.12.0a2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://4suite.org/
COMMENT=	XML processing tools

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

#pyxml is needed at runtime to get pyexpat
#.include "../../textproc/py-xml-base/buildlink.mk"
#.include "../../lang/python/application.buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
