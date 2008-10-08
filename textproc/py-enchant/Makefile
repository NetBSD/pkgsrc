# $NetBSD: Makefile,v 1.1.1.1 2008/10/08 09:42:47 wiz Exp $
#

DISTNAME=	pyenchant-1.4.2
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyenchant/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyenchant.sourceforge.net/
COMMENT=	Spellchecking library for Python

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
