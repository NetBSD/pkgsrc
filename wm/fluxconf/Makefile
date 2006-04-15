# $NetBSD: Makefile,v 1.1.1.1 2006/04/15 09:39:39 xtraeme Exp $
#

DISTNAME=	fluxconf-0.9.9
CATEGORIES=	wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://devaux.fabien.free.fr/flux/
COMMENT=	GTK based configuration tool for the fluxbox window manager

DEPENDS+=		fluxbox-[0-9]*:../../wm/fluxbox

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
