# $NetBSD: Makefile,v 1.5 2025/08/25 08:35:14 wiz Exp $

DISTNAME=	mtime-1.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	https://erratique.ch/software/mtime/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/mtime/releases/
COMMENT=	Monotonic wall-clock time for OCaml
LICENSE=	isc

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "options.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
