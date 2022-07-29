# $NetBSD: Makefile,v 1.89 2022/07/29 06:05:49 rin Exp $

DISTNAME=	Eterm-0.9.6
PKGNAME=	${DISTNAME:S/^E/e/}
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eterm/}
DISTFILES=	${DEFAULT_DISTFILES} ${PIXMAP_FILES}
PIXMAP_FILES=	Eterm-bg-0.9.5.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eterm.org/
COMMENT=	Enlightened terminal emulator for the X Window System
LICENSE=	mit

USE_TOOLS+=		perl:run
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-multi-charset=unicode
CONFIGURE_ARGS+=	--enable-auto-encoding

CONFIGURE_ARGS+=	--enable-trans
CONFIGURE_ARGS+=	--disable-utmp

PKG_SYSCONFSUBDIR=	Eterm
OWN_DIRS=		${PKG_SYSCONFDIR}/themes

EXTRACT_DIR.${PIXMAP_FILES}=	${WRKSRC}

.include "options.mk"
.include "../../devel/libast/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
BUILDLINK_DEPMETHOD.iconv?=	build
.include "../../mk/bsd.pkg.mk"
