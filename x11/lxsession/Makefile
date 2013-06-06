# $NetBSD: Makefile,v 1.5 2013/06/06 12:55:19 wiz Exp $

DISTNAME=	lxsession-0.4.6.1
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Session manager for LXDE

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
INSTALLATION_DIRS=	share/doc/lxsession
USE_TOOLS+=	intltool pkg-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/lxsession/

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
