# $NetBSD: Makefile,v 1.20 2013/02/16 11:24:46 wiz Exp $
#

DISTNAME=	fluxconf-0.9.9
PKGREVISION=	15
CATEGORIES=	wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://devaux.fabien.free.fr/flux/
COMMENT=	GTK based configuration tool for the fluxbox window manager

DEPENDS+=		fluxbox-[0-9]*:../../wm/fluxbox

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${PKGLOCALEDIR}
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=invalid-source-encoding
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
