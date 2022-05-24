# $NetBSD: Makefile,v 1.25 2022/05/24 18:51:56 jaapb Exp $
#

DISTNAME=	calendar-2.04
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	time devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1481/

MAINTAINER=	jaapb@kerguelen.org
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
