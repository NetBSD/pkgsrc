# $NetBSD: Makefile,v 1.13 2011/11/01 06:03:05 sbd Exp $
#

DISTNAME=	kiwi-1.9.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/kiwi/1.9/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.async.com.br/projects/kiwi/
COMMENT=	Framework and a set of enhanced PyGTK widgets

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

PYTHON_VERSIONS_ACCEPTED=	27 26 25
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools
INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
