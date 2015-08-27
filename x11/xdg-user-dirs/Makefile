# $NetBSD: Makefile,v 1.8 2015/08/27 21:44:59 wiz Exp $

DISTNAME=	xdg-user-dirs-0.15
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://user-dirs.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/xdg-user-dirs
COMMENT=	Tool to manage "well known" user directories
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

EGDIR=	${PREFIX}/share/examples/xdg

CONF_FILES+=	${EGDIR}/user-dirs.conf \
		${PKG_SYSCONFDIR}/xdg/user-dirs.conf
CONF_FILES+=	${EGDIR}/user-dirs.defaults \
		${PKG_SYSCONFDIR}/xdg/user-dirs.defaults

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
