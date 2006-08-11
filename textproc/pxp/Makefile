# $NetBSD: Makefile,v 1.2 2006/08/11 15:46:03 wiz Exp $
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

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
