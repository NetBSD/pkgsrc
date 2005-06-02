# $NetBSD: Makefile,v 1.2.2.1 2005/06/02 00:59:25 salo Exp $
#

DISTNAME=	lablgtk-2.4.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/
COMMENT=	GTK+ 2.x bindings for Objective Caml

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

BUILDLINK_DEPMETHOD.ocaml=	full

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
