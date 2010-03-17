# $NetBSD: Makefile,v 1.2 2010/03/17 19:51:50 joerg Exp $
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

PYTHON_VERSIONS_ACCEPTED=	26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
