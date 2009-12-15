# $NetBSD: Makefile,v 1.17 2009/12/15 22:18:09 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		3

CONFIGURE_ARGS+=	--disable-tk

PTHREAD_AUTO_VARS=	yes

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
