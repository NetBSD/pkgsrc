# $NetBSD: Makefile,v 1.5 2002/03/18 09:23:00 wiz Exp $
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

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_PERL5=		YES
USE_X11BASE=		YES

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
