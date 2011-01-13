# $NetBSD: Makefile,v 1.9 2011/01/13 13:39:32 wiz Exp $
#

DISTNAME=	fluxconf-0.9.9
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://devaux.fabien.free.fr/flux/
COMMENT=	GTK based configuration tool for the fluxbox window manager

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		fluxbox-[0-9]*:../../wm/fluxbox

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${PKGLOCALEDIR}
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
