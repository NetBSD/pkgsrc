# $NetBSD: Makefile,v 1.8 2017/09/04 18:55:10 wiz Exp $

DISTNAME=	iniparse-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	http://iniparse.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/iniparse/
COMMENT=	Better INI parser for Python
LICENSE=	mit AND python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/doc/iniparse-0.4/index.html

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
