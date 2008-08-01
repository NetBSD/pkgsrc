# $NetBSD: Makefile,v 1.1.1.1 2008/08/01 08:31:38 obache Exp $
#

DISTNAME=	Pygments-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pygments/	\
		${MASTER_SITE_SOURCEFORGE:=pygments/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://pygments.org/
COMMENT=	Python syntax highlighter

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
