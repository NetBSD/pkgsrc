# $NetBSD: Makefile,v 1.8 2020/11/05 09:07:18 ryoon Exp $

GITHUB_PROJECT=	lablgtk
GITHUB_TAG=	${VERSION}
VERSION=	3.1.0
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${GITHUB_PROJECT}3-${VERSION}
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=garrigue/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/garrigue/lablgtk/
COMMENT=	GTK+ 3.x bindings for OCaml
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

OCAML_USE_DUNE=		yes
OCAML_FINDLIB_DIRS=	lablgtk3
OPAM_INSTALL_FILES=	lablgtk3
DUNE_BUILD_PACKAGES=	lablgtk3


.include "../../mk/ocaml.mk"

.include "options.mk"

.include "../../graphics/ocaml-cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
