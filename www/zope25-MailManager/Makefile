# $NetBSD: Makefile,v 1.1.1.1 2003/08/11 15:22:24 drochner Exp $

DISTNAME=	MailManager-0.94
PKGNAME=	zope25-MailManager-0.94
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailmanager/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mailmanager.sourceforge.net/
COMMENT=	Mail management and issue tracking

DEPENDS+=	zope25-CookieCrumbler>=1.1:../../www/zope25-CookieCrumbler
DEPENDS+=	zope25-BTreeFolder2-[0-9]*:../../www/zope25-BTreeFolder2
DEPENDS+=	zope25-StripoGram>=1.4:../../www/zope25-StripoGram
DEPENDS+=	zope25-Epoz>=0.5.1:../../www/zope25-Epoz

USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../net/py-mimelib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
