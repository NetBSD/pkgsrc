# $NetBSD: Makefile,v 1.40 2021/03/08 08:13:10 jaapb Exp $

GITHUB_PROJECT=	graphics
DISTNAME=	ocaml-${GITHUB_PROJECT}-2.0.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/graphics/
COMMENT=	OCaml graphics library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
