# $NetBSD: Makefile,v 1.24 2010/03/04 20:42:01 gls Exp $

DISTNAME=	suite3270-3.3.10ga4-src
PKGNAME=	x3270-3.3.10ga4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=x3270/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x3270.bgp.nu/
COMMENT=	3270 Terminal emulator

GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/x3270-3.3
USE_IMAKE=	yes

FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc

EGDIR=			${PREFIX}/share/examples/x3270
CONF_FILES=		${EGDIR}/ibm_hosts ${PKG_SYSCONFDIR}/ibm_hosts

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
