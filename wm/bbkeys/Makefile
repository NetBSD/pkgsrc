# $NetBSD: Makefile,v 1.19 2006/08/20 23:08:44 jschauma Exp $
#

DISTNAME=	bbkeys-0.8.6
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

CONFLICTS+=	bbkeys09-*

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
