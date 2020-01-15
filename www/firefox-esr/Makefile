# $NetBSD: Makefile,v 1.1 2020/01/15 20:42:10 nia Exp $

ESR_VER=	68
PKGNAME=	firefox-esr-${ESR_VER}
CATEGORIES=	www meta-pkgs
DISTFILES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://support.mozilla.org/en-US/kb/firefox-esr-release-cycle
COMMENT=	Meta-package for installing the most recent Firefox ESR version

META_PACKAGE=	yes

DEPENDS+=	firefox${ESR_VER}-[0-9]*:../../www/firefox${ESR_VER}

.include "../../mk/bsd.pkg.mk"
