# $NetBSD: Makefile,v 1.1.1.1 2003/07/24 20:14:48 wiz Exp $
#

DISTNAME=		bk_edit-0.6.21
PKGNAME=		${DISTNAME:S/_//}
CATEGORIES=		www
MASTER_SITES=		http://www2.fht-esslingen.de/~clfuit00/sasnt/packages/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www2.fht-esslingen.de/~clfuit00/sasnt/bk_edit/
COMMENT=		Bookmark manager and editor

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
