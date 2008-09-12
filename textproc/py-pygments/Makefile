# $NetBSD: Makefile,v 1.2 2008/09/12 05:32:38 epg Exp $
#

DISTNAME=	Pygments-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pygments/	\
		${MASTER_SITE_SOURCEFORGE:=pygments/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://pygments.org/
COMMENT=	Python syntax highlighter

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
