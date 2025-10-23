# $NetBSD: Makefile,v 1.7 2025/10/23 01:38:10 gutteridge Exp $

ESR_VER=	140
PKGNAME=	firefox-esr-${ESR_VER}
CATEGORIES=	www meta-pkgs
DISTFILES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://support.mozilla.org/en-US/kb/firefox-esr-release-cycle
COMMENT=	Meta-package for installing the most recent Firefox ESR version

META_PACKAGE=	yes

DEPENDS+=	firefox${ESR_VER}>=${ESR_VER}.0.0:../../www/firefox${ESR_VER}

.include "../../mk/bsd.pkg.mk"
