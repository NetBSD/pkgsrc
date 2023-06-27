# $NetBSD: Makefile,v 1.33 2023/06/27 10:28:34 riastradh Exp $

DISTNAME=		xinit-1.4.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X init program
LICENSE=		mit

DEPENDS+=		mcookie-[0-9]*:../../x11/mcookie

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xinit=${PREFIX}/bin/xinit --without-launchd
USE_TOOLS+=		pkg-config xauth:run

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${TOOLBASE}/bin/tradcpp -Uunix"
CONFIGURE_ENV+=		ac_cv_path_MCOOKIE="${PREFIX}/bin/mcookie"

INSTALL_MAKE_FLAGS+=	xinitrcdir=${PREFIX}/share/examples/xinit
CONF_FILES=		${PREFIX}/share/examples/xinit/xinitrc ${PREFIX}/etc/X11/xinit/xinitrc
MAKE_DIRS=		${PREFIX}/etc/X11/xinit

X11_BIN_NAME=	xinit
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
