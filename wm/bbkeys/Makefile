# $NetBSD: Makefile,v 1.6 2002/08/25 21:51:27 jlam Exp $
#

DISTNAME=	bbkeys-0.8.4
CATEGORIES=	x11 wm
MASTER_SITES=	http://bbkeys.sourceforge.net/downloads/
# I'd like to add the next line, but the file there has the same name,
# but is just a tar, not a tar.gz. [wiz 2002-03-18]
#		${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
