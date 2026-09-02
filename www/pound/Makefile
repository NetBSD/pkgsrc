# $NetBSD: Makefile,v 1.21 2026/09/02 19:05:01 wiz Exp $

DISTNAME=	pound-4.23
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=graygnuorg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/graygnuorg/pound
COMMENT=	Light-weight reverse proxy, load balancer and HTTPS front-end for Web servers
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_FEATURES.openssl=	threads

RCD_SCRIPTS=		pound

SUBST_CLASSES=		config
SUBST_MESSAGE.config=	Fixing path to default config file.
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	doc/pound.8
SUBST_SED.config=	-e "s,/usr/local/etc/,"${PKG_SYSCONFDIR}"/,g"

USE_TOOLS+=		autoconf automake autoreconf makeinfo perl

TEXINFO_REQD+=		7.0

LUA_VERSIONS_ACCEPTED=	54 53
.include "../../lang/lua/luaversion.mk"

# from 'bootstrap'
pre-configure:
	cd ${WRKSRC} && \
	perl md2txt.pl -l 4 README.md > README && \
	autoreconf -fiv

.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
