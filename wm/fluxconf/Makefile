# $NetBSD: Makefile,v 1.37 2018/11/14 22:22:33 kleink Exp $
#

DISTNAME=	fluxconf-0.9.9
PKGREVISION=	29
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
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=invalid-source-encoding -Wno-error=format-security -Wno-error=self-assign
CWRAPPERS_APPEND.cc+=	-Wno-error=invalid-source-encoding -Wno-error=format-security -Wno-error=self-assign
.elif !empty(PKGSRC_COMPILER:Mgcc)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=unused-but-set-parameter -Wno-error=unused-but-set-variable
CWRAPPERS_APPEND.cc+=	-Wno-error=unused-but-set-parameter -Wno-error=unused-but-set-variable
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
