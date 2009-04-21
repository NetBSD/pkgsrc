# $NetBSD: Makefile,v 1.5 2009/04/21 15:15:04 wiz Exp $
#

DISTNAME=	python-dateutil-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://labix.org/download/python-dateutil/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://labix.org/python-dateutil
COMMENT=	Extensions to the standard datetime module

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
