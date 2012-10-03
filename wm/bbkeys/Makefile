# $NetBSD: Makefile,v 1.24 2012/10/03 21:58:24 wiz Exp $
#

DISTNAME=	bbkeys-0.8.6
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbkeys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bbkeys.sourceforge.net/
COMMENT=	General X Window keygrabber

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	bbkeys09-*

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
