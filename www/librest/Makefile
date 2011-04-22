# $NetBSD: Makefile,v 1.2 2011/04/22 13:42:22 obache Exp $
#

DISTNAME=	rest-0.6
PKGNAME=	librest-0.6
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://moblin.org/sites/all/files/
#http://meego.gitorious.org/meego-middleware/librest

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moblin.org/projects/librest
COMMENT=	Library for "RESTful" web services
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	rest.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
