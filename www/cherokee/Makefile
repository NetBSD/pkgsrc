# $NetBSD: Makefile,v 1.16 2011/11/16 01:33:19 sbd Exp $
#

DISTNAME=	cherokee-1.0.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/1.0/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherokee-project.com/
COMMENT=	Flexible and fast web server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-wwwroot=${PREFIX}/share/cherokee

PKGCONFIG_OVERRIDE=	cherokee.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}/cherokee
OWN_DIRS+=		${VARBASE}/log
OWN_DIRS+=		${VARBASE}/run
EGDIR=			${PREFIX}/share/examples/cherokee
MESSAGE_SUBST+=		EGDIR=${EGDIR}
CONF_FILES+=		${EGDIR}/cherokee/cherokee.conf \
			${PKG_SYSCONFDIR}/cherokee/cherokee.conf

RCD_SCRIPTS=		cherokee

INSTALLATION_DIRS+=	${EGDIR}/pam.d

.include "options.mk"

# Need to installation
#TEST_TARGET=		test

BUILD_DEFS+=		VARBASE

REPLACE_PYTHON=		admin/server.py admin/upgrade_config.py

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
