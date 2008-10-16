# $NetBSD: Makefile,v 1.1.1.1 2008/10/16 20:06:11 drochner Exp $

DISTNAME=	gdata.py-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.py//}
CATEGORIES=	www python
MASTER_SITES=	http://gdata-python-client.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/gdata-python-client/
COMMENT=	Google Data API Python client library

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
