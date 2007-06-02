# $NetBSD: Makefile,v 1.1.1.1 2007/06/02 08:27:43 agc Exp $
#

DISTNAME=	nucleo-0.6
CATEGORIES=	x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/0.4.0-rc4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://insitu.lri.fr/metisse/
COMMENT=	Toolkit to explore new uses of video and HCI techniques

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
