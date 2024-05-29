# $NetBSD: Makefile,v 1.83 2024/05/29 16:35:08 adam Exp $

GITHUB_PROJECT=	lablgtk
DISTNAME=	${GITHUB_PROJECT}-2.18.13
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=garrigue/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/garrigue/lablgtk
COMMENT=	GTK+ 2.x bindings for Objective Caml
# for installed files; more restrictions on applications/
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--without-gnomecanvas
CONFIGURE_ARGS+=	--without-gnomeui
CONFIGURE_ARGS+=	--without-gtksourceview
CONFIGURE_ARGS+=	--without-panel
USE_TOOLS+=		gmake pkg-config
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	lablgtk2

MAKE_JOBS_SAFE=		no
BUILD_TARGET=		world

BUILDLINK_DEPMETHOD.ocaml=	full

CONFLICTS=	lablgtk-[0-9]*
SUPERSEDES=	lablgtk-[0-9]*

CONFIGURE_ENV+=	OCAML_SITELIBDIR="${OCAML_SITELIBDIR}"

.include "../../mk/bsd.prefs.mk"

# Stub libraries for functions missing from base system.
PLIST_VARS+=	stubs

.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || \
    ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "SunOS"  || ${OPSYS} == "Linux"
PLIST.stubs=	yes
.endif

.include "../../lang/ocaml/ocaml.mk"

.include "options.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
