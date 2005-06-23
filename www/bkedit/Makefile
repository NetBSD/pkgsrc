# $NetBSD: Makefile,v 1.10 2005/06/23 23:52:57 wiz Exp $
#

DISTNAME=		bk_edit-0.6.23
PKGNAME=		${DISTNAME:S/_//}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.allesdurcheinander.de/nettools/bk_edit/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.allesdurcheinander.de/nettools/bk_edit/
COMMENT=		Bookmark manager and editor

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAKE_ENV+=		PKG_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=		PKG_LDFLAGS=${LDFLAGS:Q}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
