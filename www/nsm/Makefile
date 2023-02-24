# $NetBSD: Makefile,v 1.10 2023/02/24 21:37:06 he Exp $

DISTNAME=	nsm-2.3.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nifty-site-manager/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nift.dev/
COMMENT=	Cross-platform git- and LaTeX-like command-line website manager
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
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
SUBST_SED.nift+=	-e 's,/usr/local/lib,${PREFIX}/lib,g'
SUBST_SED.nift+=	-e 's,CXXFLAGS=-std=c++11,CXXFLAGS+=-std=c++11,g'
SUBST_SED.nift+=	-e 's,LINK=,LDFLAGS+=,g'
SUBST_SED.nift+=	-e 's,LINK+=,LDFLAGS+=,g'
SUBST_SED.nift+=	-e 's,-O3,,g'

MAKE_ENV+=	BUNDLED=0
MAKE_ENV+=	LUA_VERSION=5.3
DL_AUTO_VARS=	yes

BUILDLINK_TRANSFORM+=	opt:-llua-5.3:-llua5.3

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s nsm nift

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../lang/lua53/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
