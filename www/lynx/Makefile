# $NetBSD: Makefile,v 1.8 1998/04/20 11:56:34 frueauf Exp $
# FreeBSD Id: Makefile,v 1.71 1997/11/24 19:35:30 ache Exp
#

DISTNAME=       lynx2.8rel.2
PKGNAME=        lynx-2.8rel.2
WRKSRC=         ${WRKDIR}/lynx2-8
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	packages@netbsd.org

LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

CONFIGURE_ARGS+= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
GNU_CONFIGURE=  YES
INSTALL_TARGET= install install-help
MAKEFILE=       makefile

MAN1=		lynx.1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
