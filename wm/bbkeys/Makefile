# $NetBSD: Makefile,v 1.8 2003/05/17 05:41:09 salo Exp $
#

DISTNAME=	bbkeys-0.8.5
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
