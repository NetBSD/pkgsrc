# $NetBSD: Makefile,v 1.20 2013/09/09 09:19:39 wiz Exp $

DISTNAME=		xinit-1.3.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X init program
LICENSE=		mit

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xinit=${PREFIX}/bin/xinit
USE_TOOLS+=		pkg-config xauth:run

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/tradcpp -Uunix"

INSTALL_MAKE_FLAGS+=	xinitrcdir=${PREFIX}/share/examples/xinit
CONF_FILES=		${PREFIX}/share/examples/xinit/xinitrc ${PREFIX}/etc/X11/xinit/xinitrc
MAKE_DIRS=		${PREFIX}/etc/X11/xinit

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
