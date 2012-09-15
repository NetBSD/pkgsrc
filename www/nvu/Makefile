# $NetBSD: Makefile,v 1.11 2012/09/15 10:06:48 obache Exp $
#

DISTNAME=	nvu-1.0-sources
PKGNAME=	${DISTNAME:S/-sources//}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nvu.com/
COMMENT=	Web Authoring System

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mozilla
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ORBIT_CONFIG=orbit2-config
USE_TOOLS+=	gmake perl pkg-config unzip zip
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	build/unix/mozilla-gtkmozembed.pc.in
PKGCONFIG_OVERRIDE+=	build/unix/mozilla-js.pc.in
PKGCONFIG_OVERRIDE+=	build/unix/mozilla-nspr.pc.in
PKGCONFIG_OVERRIDE+=	build/unix/mozilla-nss.pc.in
PKGCONFIG_OVERRIDE+=	build/unix/mozilla-plugin.pc.in
PKGCONFIG_OVERRIDE+=	build/unix/mozilla-xpcom.pc.in

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libIDL}/include/libIDL-2.0
BUILDLINK_TRANSFORM+=	l:IDL:IDL-2

.include "../../net/libIDL/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
