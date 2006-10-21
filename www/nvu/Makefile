# $NetBSD: Makefile,v 1.1.1.1 2006/10/21 21:54:12 rillig Exp $
#

DISTNAME=	nvu-1.0-sources
PKGNAME=	nvu-1.0
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.nvu.com/
COMMENT=	Web Authoring System

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

WRKSRC=		${WRKDIR}/mozilla
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config unzip
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
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
