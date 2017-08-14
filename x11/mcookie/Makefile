# $NetBSD: Makefile,v 1.10 2017/08/14 21:17:14 wiz Exp $
#
# Changelog: see
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.c
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.1

DISTNAME=	util-linux-2.30.1
PKGNAME=	${DISTNAME:S/util-linux/mcookie/}
CATEGORIES=	sysutils
MASTER_SITES=	https://www.kernel.org/pub/linux/utils/util-linux/v2.30/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE
COMMENT=	Tool for creating cookies for xauth(1)
LICENSE=	public-domain

BUILD_TARGET=	mcookie
EXTRACT_USING=	bsdtar

CONFIG_SHELL=		bash
GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_TOOLS+=		bash bsdtar gmake
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CONFIGURE_ENV.DragonFly+=	ac_cv_type_cpu_set_t=no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcookie ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/misc-utils/mcookie.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
