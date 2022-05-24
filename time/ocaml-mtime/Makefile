# $NetBSD: Makefile,v 1.4 2022/05/24 18:51:56 jaapb Exp $

DISTNAME=	mtime-1.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	https://erratique.ch/software/mtime/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/mtime/releases/
COMMENT=	Monotonic wall-clock time for OCaml
LICENSE=	isc

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "options.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
