# $NetBSD: Makefile,v 1.39 2024/02/04 20:00:52 wiedi Exp $

DISTNAME=	goaccess-1.9
CATEGORIES=	www
MASTER_SITES=	https://tar.goaccess.io/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://goaccess.io/
COMMENT=	Real-time web log analyzer and viewer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config aclocal autoconf automake

USE_CURSES=	getmouse
FAKE_NCURSES=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/goaccess.conf ${PKG_SYSCONFDIR}/goaccess.conf

LIBS.SunOS+=		-lsocket -lnsl
CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.NetBSD+=	-lterminfo

BROKEN_GETTEXT_DETECTION=	yes

.include "../../mk/bsd.prefs.mk"

GOACCESS_USER?=		${APACHE_USER}
GOACCESS_GROUP?=	${APACHE_GROUP}

BUILD_DEFS+=		VARBASE GOACCESS_USER GOACCESS_GROUP

PKG_USERS_VARS=		GOACCESS_USER
PKG_GROUPS_VARS=	GOACCESS_GROUP
PKG_GROUPS=		${GOACCESS_GROUP}
PKG_USERS=		${GOACCESS_USER}:${GOACCESS_GROUP}

RCD_SCRIPTS+=		goaccess
FILES_SUBST+=		GOACCESS_USER=${GOACCESS_USER:Q}

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
