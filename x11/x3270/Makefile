# $NetBSD: Makefile,v 1.30 2011/11/24 20:07:48 gls Exp $

DISTNAME=	suite3270-3.3.12ga7-src
PKGNAME=	x3270-3.3.12ga7
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=x3270/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://x3270.bgp.nu/
COMMENT=	3270 Terminal emulator
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/x3270-3.3
USE_IMAKE=	yes
USE_TOOLS+=	bdftopcf

FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc
IMAKEOPTS+=		-DFontDir=${PREFIX}/lib/X11/fonts

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

PKG_SYSCONFSUBDIR=	x3270

EGDIR=			${PREFIX}/share/examples/x3270
CONF_FILES=		${EGDIR}/ibm_hosts ${PKG_SYSCONFDIR}/ibm_hosts
INSTALLATION_DIRS+=	${EGDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
