# $NetBSD: Makefile,v 1.23 2020/03/22 22:46:27 roy Exp $

DISTNAME=	goaccess-1.3
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://tar.goaccess.io/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	http://goaccess.prosoftcorp.com/
COMMENT=	Real-time web log analyzer
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

BROKEN_GETTEXT_DETECTION=	yes

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
