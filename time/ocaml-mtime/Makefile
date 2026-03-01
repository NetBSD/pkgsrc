# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:40 gdt Exp $

DISTNAME=	mtime-1.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
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
