# $NetBSD: Makefile,v 1.20 2011/07/30 10:17:41 cheusov Exp $
#

DISTNAME=		bk_edit-0.6.23
PKGNAME=		${DISTNAME:S/_//}
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		http://www.vakuumverpackt.de/nettools/bk_edit/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.vakuumverpackt.de/nettools/bk_edit/
COMMENT=		Bookmark manager and editor

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		bison lex

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAKE_ENV+=		PKG_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=		PKG_LDFLAGS=${LDFLAGS:Q}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
