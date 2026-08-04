# $NetBSD: Makefile,v 1.39 2026/08/04 20:29:19 wiz Exp $

DISTNAME=		bk_edit-0.6.23
PKGNAME=		${DISTNAME:S/_//}
PKGREVISION=		18
CATEGORIES=		www
#MASTER_SITES=		http://www.vakuumverpackt.de/nettools/bk_edit/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.vakuumverpackt.de/nettools/bk_edit/
COMMENT=		Bookmark manager and editor

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		bison lex

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAKE_ENV+=		PKG_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=		PKG_LDFLAGS=${LDFLAGS:Q}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-export-dynamic

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
