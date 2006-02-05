# $NetBSD: Makefile,v 1.17 2006/02/05 23:11:12 joerg Exp $
#

DISTNAME=	bbkeys-0.8.6
PKGREVISION=	1
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
