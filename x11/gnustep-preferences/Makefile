# $NetBSD: Makefile,v 1.25 2006/07/21 04:57:27 rillig Exp $
#

DISTNAME=	Preferences-1.2.0
PKGNAME=	gnustep-${DISTNAME:S/P/p/}
PKGREVISION=	14
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prefsapp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://prefsapp.sourceforge.net/
COMMENT=	Application for setting preferences for the GNUstep system

USE_LANGUAGES=	c objc

NO_CONFIGURE=	YES
USE_TOOLS+=	gmake
MAKEFILE=	GNUmakefile

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
