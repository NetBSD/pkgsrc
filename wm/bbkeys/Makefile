# $NetBSD: Makefile,v 1.9 2003/05/22 15:39:31 jschauma Exp $
#

DISTNAME=	bbkeys-0.8.6
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
