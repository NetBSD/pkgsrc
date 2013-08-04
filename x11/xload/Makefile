# $NetBSD: Makefile,v 1.12 2013/08/04 07:28:57 wiz Exp $

DISTNAME=	xload-1.1.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	System load average display for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config xgettext

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
