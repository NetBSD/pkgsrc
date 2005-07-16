# $NetBSD: Makefile,v 1.16 2005/07/16 19:10:40 jlam Exp $
#

DISTNAME=	bbkeys-0.8.6
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++
USE_TOOLS+=	perl:run

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
