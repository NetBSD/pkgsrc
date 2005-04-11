# $NetBSD: Makefile,v 1.3 2005/04/11 21:48:03 tv Exp $

DISTNAME=	MailManager-0.94
PKGNAME=	zope25-MailManager-0.94
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailmanager/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mailmanager.sourceforge.net/
COMMENT=	Mail management and issue tracking

DEPENDS+=	${PYPKGPREFIX}-mimelib-[0-9]*:../../net/py-mimelib
DEPENDS+=	zope25-CookieCrumbler>=1.1:../../www/zope25-CookieCrumbler
DEPENDS+=	zope25-BTreeFolder2-[0-9]*:../../www/zope25-BTreeFolder2
DEPENDS+=	zope25-StripoGram>=1.4:../../www/zope25-StripoGram
DEPENDS+=	zope25-Epoz>=0.5.1:../../www/zope25-Epoz


.include "../../www/zope25/product.mk"
.include "../../mk/bsd.pkg.mk"
