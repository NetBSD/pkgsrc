# $NetBSD: Makefile,v 1.2 2003/08/01 18:12:10 wiz Exp $
#

DISTNAME=		bk_edit-0.6.21
PKGNAME=		${DISTNAME:S/_//}
CATEGORIES=		www
MASTER_SITES=		http://www2.fht-esslingen.de/~clfuit00/sasnt/packages/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www2.fht-esslingen.de/~clfuit00/sasnt/bk_edit/
COMMENT=		Bookmark manager and editor

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
