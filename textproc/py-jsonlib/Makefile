# $NetBSD: Makefile,v 1.3 2011/02/25 09:47:28 wiz Exp $
#

DISTNAME=	jsonlib-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/j/jsonlib/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://launchpad.net/jsonlib
COMMENT=	JSON serializer/deserializer for Python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	27 26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
