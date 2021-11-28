# $NetBSD: Makefile,v 1.10 2021/11/28 19:48:57 pin Exp $

DISTNAME=	badwolf-1.2.2
CATEGORIES=	www
#MASTER_SITES=	https://hacktivis.me/releases/
MASTER_SITES=	https://gitlab.com/lanodan/badWolf/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://hacktivis.me/projects/badwolf
COMMENT=	Minimalist and privacy-oriented webkit browser
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/badWolf-v1.2.2-ca225a55af3a723ff094c6be87254b66a947a518

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	configure
SUBST_SED.prefix+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.prefix+=	-e 's/cc/${CC:Q}/'
SUBST_SED.prefix+=	-e 's,^CFLAGS *= ,CFLAGS += ,'

pre-configure:
	cd ${WRKSRC} && ./configure

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
