# $NetBSD: Makefile,v 1.3 2010/02/12 00:31:52 joerg Exp $
#

DISTNAME=	calendar-2.0.4
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	time devel
MASTER_SITES=	# http://www.lri.fr/~signoles/prog/calendar/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://www.lri.fr/~signoles/prog.en.html/
COMMENT=	OCaml library managing dates and times

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS+=	lib/ocaml/site-lib

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
