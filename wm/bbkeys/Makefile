# $NetBSD: Makefile,v 1.33 2020/01/18 23:35:40 rillig Exp $
#

DISTNAME=	bbkeys-0.8.6
PKGREVISION=	8
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

CONFLICTS+=	bbkeys09-[0-9]*

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
