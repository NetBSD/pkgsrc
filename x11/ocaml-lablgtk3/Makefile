# $NetBSD: Makefile,v 1.39 2025/01/19 19:01:22 wiz Exp $

DISTNAME=	lablgtk-3.1.5
PKGNAME=	ocaml-${DISTNAME:S/lablgtk/lablgtk3/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=garrigue/}
GITHUB_PROJECT=	lablgtk
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/garrigue/lablgtk/
COMMENT=	GTK+ 3.x bindings for OCaml
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

OCAML_USE_DUNE=		yes
OCAML_FINDLIB_DIRS=	lablgtk3
OPAM_INSTALL_FILES=	${OCAML_FINDLIB_DIRS}
DUNE_BUILD_PACKAGES=	${OCAML_FINDLIB_DIRS}

.include "../../lang/ocaml/ocaml.mk"

.include "options.mk"

.include "../../devel/camlp-streams/buildlink3.mk"
.include "../../graphics/ocaml-cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
