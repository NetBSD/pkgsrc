# $NetBSD: Makefile,v 1.8 2010/04/09 08:33:38 tnn Exp $
#

DISTNAME=		xextproto-7.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XExt extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xextproto.pc.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/shmstr.h ${DESTDIR}${PREFIX}/include/X11/extensions

.include "../../mk/bsd.pkg.mk"
