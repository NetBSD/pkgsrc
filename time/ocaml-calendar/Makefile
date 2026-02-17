# $NetBSD: Makefile,v 1.27 2026/02/17 13:39:14 wiz Exp $
#

DISTNAME=	calendar-2.04
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	time devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1481/

MAINTAINER=	pkgsrc-users@kerguelen.org
HOMEPAGE=	http://calendar.forge.ocamlcore.org/
COMMENT=	OCaml library managing dates and times
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
OCAML_USE_FINDLIB=	yes

.include "../../mk/bsd.prefs.mk"

TEST_TARGET=	tests

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
