# $NetBSD: Makefile,v 1.2 2009/05/30 01:00:11 zafer Exp $
#

DISTNAME=	calendar-2.0.4
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	time devel
MASTER_SITES=	# http://www.lri.fr/~signoles/prog/calendar/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://www.lri.fr/~signoles/prog.en.html/
COMMENT=	OCaml library managing dates and times

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SRC+=	PLIST.opt
.endif

PLIST_SRC+=	PLIST

TEST_TARGET=	tests

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
