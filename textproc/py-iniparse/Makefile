# $NetBSD: Makefile,v 1.2 2014/01/03 03:50:26 rodent Exp $

DISTNAME=	iniparse-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	http://iniparse.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/iniparse/
COMMENT=	Better INI parser for Python
LICENSE=	mit AND python-software-foundation

USE_LANGUAGES=	# none

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/doc/iniparse-0.4/index.html

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
