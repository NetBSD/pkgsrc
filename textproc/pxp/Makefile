# $NetBSD: Makefile,v 1.3 2009/11/26 18:21:28 joerg Exp $
#

DISTNAME=		pxp-1.1.6
CATEGORIES=		textproc
MASTER_SITES=		http://www.ocaml-programming.de/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ocaml-programming.de/packages/
COMMENT=		Polymorphic XML parser, a validating XML-1.0 parser (OCaml)

DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=		ocamlnet-[0-9]*:../../net/ocamlnet

USE_TOOLS+=		gmake
BUILD_TARGET=		all opt
HAS_CONFIGURE=		yes
PLIST_SRC=		PLIST.opt PLIST

MAKE_JOBS_SAFE=		no

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
