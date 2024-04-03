# $NetBSD: Makefile,v 1.19 2024/04/03 21:19:42 wiz Exp $

DISTNAME=	xload-1.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	System load average display for X

BROKEN_GETTEXT_DETECTION=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config xgettext

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
