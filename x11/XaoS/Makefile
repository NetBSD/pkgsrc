# $NetBSD: Makefile,v 1.38 2015/12/29 13:41:58 bsiegert Exp $
#

DISTNAME=		xaos-3.6
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xaos/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matek.hu/xaos/
COMMENT=		Zoomable fractal rendering doodad
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INFO_FILES=		yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e 's,/usr/share/locale,${PREFIX}/${PKGLOCALEDIR}/locale,g'

INSTALLATION_DIRS=	${PKGINFODIR}

CHECK_PORTABILITY_SKIP+=	help/applehelpconv
CHECK_PORTABILITY_SKIP+=	help/.svn/text-base/applehelpconv.svn-base

LDFLAGS.SunOS+=		-liconv

.include "../../math/gsl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
