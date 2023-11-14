# $NetBSD: Makefile,v 1.3 2023/11/14 14:03:13 wiz Exp $

DISTNAME=	i3lock-color-2.13.c.4
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Raymo111/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Raymo111/i3lock-color/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf
USE_LANGUAGES=	c99
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/i3lock

EGDIR=	${PREFIX}/share/examples/i3lock

MESSAGE_SUBST+=	EGDIR=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFBASEDIR}/pam.d
CONF_FILES+=	${EGDIR}/pam.d/i3lock ${PKG_SYSCONFBASEDIR}/pam.d/i3lock

CONFLICTS+=	i3lock-[0-9]*

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -if

.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
#.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
