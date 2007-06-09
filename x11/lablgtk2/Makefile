# $NetBSD: Makefile,v 1.24 2007/06/09 13:17:18 wiz Exp $
#

DISTNAME=	lablgtk-2.6.0
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
PKGREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ 2.x bindings for Objective Caml

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

BUILD_TARGET=		world

BUILDLINK_DEPMETHOD.ocaml=	full

# previous name of this package; does not conflict with lablgtk-1.*
CONFLICTS=	lablgtk-2.*

.include "options.mk"

.include "../../lang/ocaml/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
