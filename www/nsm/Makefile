# $NetBSD: Makefile,v 1.4 2019/12/10 17:37:45 ng0 Exp $

DISTNAME=	nsm-1.23
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nifty-site-manager/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://www.nift.cc/
COMMENT=	Cross-platform git- and LaTeX-like command-line website manager
LICENSE=	mit

USE_LANGUAGES=		c++
INSTALLATION_DIRS=	bin

# Avoid building 2 binaries with the exact same content
# where we can symlink instead. This safes 50 percent
# of the binary size and some double computation.
# closed upstream ticket:
# https://github.com/nifty-site-manager/nsm/issues/2
SUBST_CLASSES+=		nift
SUBST_STAGE.nift=	pre-configure
SUBST_FILES.nift=	Makefile
SUBST_SED.nift=		-e '/nift/ s,^,\#,g'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s nsm nift

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
