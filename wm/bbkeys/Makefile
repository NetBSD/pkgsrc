# $NetBSD: Makefile,v 1.13 2004/11/22 21:01:09 wiz Exp $
#

DISTNAME=	bbkeys-0.8.6
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=	YES
USE_LANGUAGES=	c++

.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
