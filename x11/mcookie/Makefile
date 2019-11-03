# $NetBSD: Makefile,v 1.14 2019/11/03 09:14:13 rillig Exp $
#
# Changelog: see
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.c
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.1

.include "../../devel/libuuid/Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/mcookie/}
CATEGORIES=	sysutils
COMMENT=	Tool for creating cookies for xauth(1)
LICENSE=	public-domain

CONFIGURE_ARGS+=		--enable-mcookie
CONFIGURE_ENV.DragonFly+=	ac_cv_type_cpu_set_t=no

.include "../../mk/bsd.pkg.mk"
