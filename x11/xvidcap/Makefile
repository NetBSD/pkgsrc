# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:40 tv Exp $
#

DISTNAME=		xvidcap-1.1.3
PKGREVISION=	1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xvidcap/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xvidcap.sourceforge.net/
COMMENT=		Capture X display to individual frames or MPEG video

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		XVIDCAP_GTK2_GUI

.if defined(XVIDCAP_GTK2_GUI) && !empty(XVIDCAP_GTK2_GUI:M[Yy][Ee][Ss])
PLIST_SUBST+=		GTK2_GUI=
CONFIGURE_ARGS+=	--with-gtk2
.  include "../../x11/gtk2/buildlink3.mk"
.else
PLIST_SUBST+=		GTK2_GUI='@comment '
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
