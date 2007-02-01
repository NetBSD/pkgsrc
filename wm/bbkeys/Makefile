# $NetBSD: Makefile,v 1.20 2007/02/01 23:11:33 joerg Exp $
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

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
