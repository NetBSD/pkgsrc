# $NetBSD: Makefile,v 1.2 2012/02/05 13:19:32 obache Exp $
#

.include "../../textproc/yamcha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES+=	python

COMMENT=	YamCha python module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python

EGG_NAME=	${DISTNAME:S/-/_python-/}

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../textproc/yamcha/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
