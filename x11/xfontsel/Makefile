# $NetBSD: Makefile,v 1.14 2024/07/07 09:08:57 cheusov Exp $

DISTNAME=		xfontsel-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X font selector

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

# Fix build failure by disabling gettext which is not used any way.
# So, we don't need xgettext(1).
CONFIGURE_ENV+=		ac_cv_search_gettext=no

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
