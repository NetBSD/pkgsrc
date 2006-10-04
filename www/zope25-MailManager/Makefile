# $NetBSD: Makefile,v 1.6 2006/10/04 22:04:11 wiz Exp $

DISTNAME=	MailManager-0.94
PKGNAME=	zope25-MailManager-0.94
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailmanager/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logicalware.org/
COMMENT=	Mail management and issue tracking

DEPENDS+=	${PYPKGPREFIX}-mimelib-[0-9]*:../../net/py-mimelib
DEPENDS+=	zope25-CookieCrumbler>=1.1:../../www/zope25-CookieCrumbler
DEPENDS+=	zope25-BTreeFolder2-[0-9]*:../../www/zope25-BTreeFolder2
DEPENDS+=	zope25-StripoGram>=1.4:../../www/zope25-StripoGram
DEPENDS+=	zope25-Epoz>=0.5.1:../../www/zope25-Epoz


.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
