# $NetBSD: Makefile,v 1.11 2016/02/02 13:33:12 mef Exp $

DISTNAME=	Pound-2.7f
PKGNAME=	${DISTNAME:S/Pound/pound/}
CATEGORIES=	www
MASTER_SITES=	http://www.apsis.ch/pound/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.apsis.ch/pound/
COMMENT=	Reverse proxy, load balancer and HTTPS front-end
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_FEATURES.openssl=	threads

RCD_SCRIPTS=		pound

SUBST_CLASSES=		config
SUBST_MESSAGE.config=	Fixing path to default config file.
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	pound.8
SUBST_SED.config=	-e "s,/usr/local/etc/,"${PKG_SYSCONFDIR:Q}"/,g"

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
