# $NetBSD: Makefile,v 1.1 2020/07/08 09:26:58 pin Exp $

DISTNAME=	badwolf-1.0.2
CATEGORIES=	www
MASTER_SITES=	https://hacktivis.me/releases/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://hacktivis.me/projects/badwolf
COMMENT=	Minimalist and privacy-oriented webkit browser
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	Makefile
SUBST_SED.prefix+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
