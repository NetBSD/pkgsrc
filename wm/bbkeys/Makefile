# $NetBSD: Makefile,v 1.10 2003/07/17 22:55:09 grant Exp $
#

DISTNAME=	bbkeys-0.8.6
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
