# $NetBSD: Makefile,v 1.9 2005/10/06 11:48:14 wiz Exp $
#

DISTNAME=	lablgtk-2.4.0
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/
COMMENT=	GTK+ 2.x bindings for Objective Caml

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

BUILD_TARGET=		world

BUILDLINK_DEPMETHOD.ocaml=	full

# previous name of this package; does not conflict with lablgtk-1.*
CONFLICTS=	lablgtk-2.*

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
