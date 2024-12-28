# $NetBSD: Makefile,v 1.15 2024/12/28 14:11:29 wiz Exp $
#
# Changelog: see
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.c
# https://git.kernel.org/cgit/utils/util-linux/util-linux.git/log/misc-utils/mcookie.1

.include "../../devel/libuuid/Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/mcookie/}
CATEGORIES=	x11 sysutils
COMMENT=	Tool for creating cookies for xauth(1)
LICENSE=	public-domain

CONFIGURE_ARGS+=		--enable-mcookie

.include "../../mk/bsd.pkg.mk"
