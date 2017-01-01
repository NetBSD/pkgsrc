# $NetBSD: Makefile,v 1.7 2017/01/01 14:44:01 wiz Exp $

DISTNAME=	iniparse-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	http://iniparse.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/iniparse/
COMMENT=	Better INI parser for Python
LICENSE=	mit AND python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/doc/iniparse-0.4/index.html

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
