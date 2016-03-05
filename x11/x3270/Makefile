# $NetBSD: Makefile,v 1.41 2016/03/05 11:29:49 jperkin Exp $

DISTNAME=	suite3270-3.3.14ga11-src
PKGNAME=	x3270-3.3.14ga11
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=x3270/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://x3270.bgp.nu/
COMMENT=	3270 Terminal emulator
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/x3270-3.3
USE_IMAKE=	yes
USE_TOOLS+=	bdftopcf

FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/misc
IMAKEOPTS+=		-DFontDir=${PREFIX}/share/fonts/X11

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-fontdir=${PREFIX}/share/fonts/X11/misc

PKG_SYSCONFSUBDIR=	x3270

EGDIR=			${PREFIX}/share/examples/x3270
CONF_FILES=		${EGDIR}/ibm_hosts ${PKG_SYSCONFDIR}/ibm_hosts
INSTALLATION_DIRS+=	${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
