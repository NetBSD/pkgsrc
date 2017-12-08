# $NetBSD: Makefile,v 1.13 2017/12/08 08:03:35 adam Exp $
#
# Changelog: see
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.c
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.1

.include "../../devel/libuuid/Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/mcookie/}
CATEGORIES=	sysutils
COMMENT=	Tool for creating cookies for xauth(1)
LICENSE=	public-domain

CONFIGURE_ARGS+=	--enable-mcookie
CONFIGURE_ENV.DragonFly+=	ac_cv_type_cpu_set_t=no

.include "../../mk/bsd.pkg.mk"
