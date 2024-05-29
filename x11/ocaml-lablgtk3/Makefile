# $NetBSD: Makefile,v 1.27 2024/05/29 16:35:08 adam Exp $

GITHUB_PROJECT=	lablgtk
GITHUB_TAG=	${VERSION}
VERSION=	3.1.3
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${GITHUB_PROJECT}3-${VERSION}
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=garrigue/}

MAINTAINER=	jaapb@NetBSD.org
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
