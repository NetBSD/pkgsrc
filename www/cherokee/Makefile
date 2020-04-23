# $NetBSD: Makefile,v 1.44 2020/04/23 15:46:01 nia Exp $

DISTNAME=	cherokee-1.2.101
PKGREVISION=	15
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/1.2/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherokee-project.com/
COMMENT=	Flexible and fast web server
LICENSE=	gnu-gpl-v2

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

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.2.101

.include "options.mk"

BUILD_DEFS+=		VARBASE

REPLACE_PYTHON=		admin/CTK/CTK-run.pre \
			admin/server.py admin/upgrade_config.py \
			cherokee/cherokee-admin-launcher \
			cherokee/cherokee-tweak

# Needs installation:
TEST_TARGET=		test

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
