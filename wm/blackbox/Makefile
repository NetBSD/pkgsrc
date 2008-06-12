# $NetBSD: Makefile,v 1.29 2008/06/12 02:14:53 joerg Exp $
#

DISTNAME=	blackbox-0.65.0
PKGREVISION=	6
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

CONFLICTS+=	blackbox70>=0.70.1

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
