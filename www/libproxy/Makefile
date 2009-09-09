# $NetBSD: Makefile,v 1.5 2009/09/09 15:11:31 drochner Exp $
#

DISTNAME=	libproxy-0.2.3
PKGREVISION=	1
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

PYTHON_VERSIONS_ACCEPTED=	25 26
BUILDLINK_API_DEPENDS.python26+= python26>=2.6.2nb4
BUILDLINK_API_DEPENDS.python25+= python25>=2.5.4nb2

.include "../../lang/python/extension.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
