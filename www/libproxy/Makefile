# $NetBSD: Makefile,v 1.2 2009/03/12 13:31:48 hasso Exp $
#

DISTNAME=	libproxy-0.2.3
CATEGORIES=	www gnome
MASTER_SITES=	http://libproxy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libproxy/
COMMENT=	Library that provides automatic proxy configuration management

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake autoreconf autoconf automake
PY_PATCHPLIST=	yes

PKGCONFIG_OVERRIDE+=	libproxy-1.0.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf --force

.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
