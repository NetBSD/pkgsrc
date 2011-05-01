# $NetBSD: Makefile,v 1.1.1.1 2011/05/01 09:20:46 obache Exp $
#

DISTNAME=	cssutils-0.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://cssutils.googlecode.com/files/ \
		http://pypi.python.org/packages/source/c/cssutils/
EXTRACT_SUFX=	.zip

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://cthedot.de/cssutils/
COMMENT=	Cascading Style Sheets parser and library for Python
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

# all files are group/others writable.
post-extract:
	chmod -R go-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
