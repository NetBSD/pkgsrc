# $NetBSD: Makefile,v 1.96 2020/06/05 12:49:17 jperkin Exp $

# The 1.3.1 release is a few years old, and upstream recommends that
# the head of svn be used.  However, we follow pkgsrc norms of
# packaging releases, with some commits applied as patches.
DISTNAME=	xplanet-1.3.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xplanet.sourceforge.net/
COMMENT=	Rotating rendered map of the Earth in X11 root window
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++11
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl
MAKE_ENV+=		PERL5=${PERL5:Q}

# \todo Fix Native PNM support
CONFIGURE_ARGS+=	--without-pnm
# \todo Remove when https://github.com/OpenSpace/Spice is in pkgsrc
CONFIGURE_ARGS+=	ac_cv_lib_cspice_furnsh_c=no

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
