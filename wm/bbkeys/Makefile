# $NetBSD: Makefile,v 1.12 2004/03/10 14:12:50 xtraeme Exp $
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
USE_GCC_SHLIB=	YES

.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
