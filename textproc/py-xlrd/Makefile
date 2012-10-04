# $NetBSD: Makefile,v 1.5 2012/10/04 00:21:59 cheusov Exp $
#

DISTNAME=		xlrd-0.7.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		http://pypi.python.org/packages/source/x/xlrd/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.lexicon.net/sjmachin/xlrd.htm
COMMENT=		Python library to extract data from Microsoft Excel spread sheet files
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
