# $NetBSD: Makefile,v 1.28.2.1 2012/10/03 12:09:58 spz Exp $
#

DISTNAME=	nucleo-0.7.5
PKGREVISION=	19
CATEGORIES=	x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/nucleo/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://insitu.lri.fr/metisse/
COMMENT=	Toolkit to explore new uses of video and HCI techniques
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes

REPLACE_PYTHON+=	docs/MacOSX/nBundle.in
PTHREAD_OPTS+=		require
###
### See options.mk for use of PLIST_VARS.
###
PLIST_VARS=		gnutls

SUBST_CLASSES+=		mkfiles
SUBST_FILES.mkfiles=	nucleo/plugins/*/Makefile.in
SUBST_MESSAGE.mkfiles=	Fixing plugin-descr targets.
SUBST_SED.mkfiles=	-e 's|@\.\ |&./|'
SUBST_STAGE.mkfiles=	post-patch

.include "../../lang/python/application.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"

BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
