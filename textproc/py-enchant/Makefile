# $NetBSD: Makefile,v 1.2 2009/02/16 19:38:27 joerg Exp $
#

DISTNAME=	pyenchant-1.4.2
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyenchant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyenchant.sourceforge.net/
COMMENT=	Spellchecking library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
