# $NetBSD: Makefile,v 1.12 2016/03/17 00:39:25 wiedi Exp $

DISTNAME=	goaccess-0.9.8
CATEGORIES=	www
MASTER_SITES=	http://tar.goaccess.io/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	http://goaccess.prosoftcorp.com/
COMMENT=	Real-time web log analyzer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=     pkg-config aclocal automake
USE_NCURSES=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/goaccess.conf ${PKG_SYSCONFDIR}/goaccess.conf

LIBS.SunOS+=	-lsocket -lnsl
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && aclocal && automake --add-missing

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
