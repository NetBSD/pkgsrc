# $NetBSD: Makefile,v 1.5 2023/01/29 21:18:33 ryoon Exp $

DISTNAME=	xst-0.8.4.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnotclub/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnotclub/xst/
COMMENT=	st fork that adds support for Xresources
LICENSE=	mit

MAKE_JOBS_SAFE=	no

CONFLICTS=	st-term-[0-9]*

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99

SUBST_CLASSES+=			configdefh configmk
SUBST_STAGE.configdefh=		pre-configure
SUBST_STAGE.configmk=		pre-configure
SUBST_MESSAGE.configdefh=	Change default font and termname
SUBST_FILES.configdefh=		config.def.h
SUBST_MESSAGE.configmk=		Fixing paths
SUBST_FILES.configmk=		config.mk
SUBST_SED.configdefh+=		-e '/font/ s,".*","monospace:size=10",'
SUBST_SED.configdefh+=		-e 's,xst-256color,xterm,g'
SUBST_SED.configmk+=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=		-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.configmk+=		-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.configmk+=		-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
