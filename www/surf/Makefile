# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:24 gutteridge Exp $

DISTNAME=	surf-2.1
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://dl.suckless.org/surf/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://surf.suckless.org/
COMMENT=	Fast and minimalistic web browser based on WebKit2/GTK+
LICENSE=	mit

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Fixing config.mk
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.configmk+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

.include "../../security/gcr/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
