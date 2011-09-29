# $NetBSD: Makefile,v 1.2 2011/09/29 11:51:32 dholland Exp $
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

PYTHON_VERSIONS_INCOMPATIBLE=	24

# all files are group/others writable.
post-extract:
	chmod -R go-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
