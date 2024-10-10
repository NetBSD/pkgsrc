# $NetBSD: Makefile,v 1.6 2024/10/10 14:09:10 wiz Exp $

ESR_VER=	128
PKGNAME=	firefox-esr-${ESR_VER}
CATEGORIES=	www meta-pkgs
DISTFILES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://support.mozilla.org/en-US/kb/firefox-esr-release-cycle
COMMENT=	Meta-package for installing the most recent Firefox ESR version

META_PACKAGE=	yes

DEPENDS+=	firefox${ESR_VER}>=${ESR_VER}.0.0:../../www/firefox${ESR_VER}

.include "../../mk/bsd.pkg.mk"
