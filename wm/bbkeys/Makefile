# $NetBSD: Makefile,v 1.7 2002/09/24 14:21:53 jschauma Exp $
#

DISTNAME=	bbkeys-0.8.5
CATEGORIES=	x11 wm
MASTER_SITES=	http://bbkeys.sourceforge.net/downloads/ \
		${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
