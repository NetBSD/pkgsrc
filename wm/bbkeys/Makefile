# $NetBSD: Makefile,v 1.39 2023/01/29 21:17:57 ryoon Exp $
#

DISTNAME=	bbkeys-0.9.1
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber
LICENSE=	mit

CONFLICTS+=	bbkeys09-[0-9]*
SUPERSEDES+=	bbkeys09-[0-9]*
PREV_PKGPATH=	wm/bbkeys09

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run pkg-config

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../wm/blackbox/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
