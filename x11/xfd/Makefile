# $NetBSD: Makefile,v 1.20 2020/08/17 20:20:39 leot Exp $

DISTNAME=	xfd-1.1.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Display all the characters in an X font

BROKEN_GETTEXT_DETECTION=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config xgettext

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
