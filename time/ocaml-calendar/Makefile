# $NetBSD: Makefile,v 1.18 2017/09/08 09:51:26 jaapb Exp $
#

DISTNAME=	calendar-2.04
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1481/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://calendar.forge.ocamlcore.org/
COMMENT=	OCaml library managing dates and times
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

.include "../../mk/bsd.prefs.mk"

TEST_TARGET=	tests

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
