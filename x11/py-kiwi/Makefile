# $NetBSD: Makefile,v 1.1.1.1 2009/01/05 12:31:06 jmcneill Exp $
#

DISTNAME=	kiwi-1.9.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/kiwi/1.9/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.async.com.br/projects/kiwi/
COMMENT=	Framework and a set of enhanced PyGTK widgets

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_PKGLOCALEDIR=	yes

PYTHON_VERSIONS_ACCEPTED=	24 25
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools
INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
