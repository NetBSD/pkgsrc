# $NetBSD: Makefile,v 1.10 2016/07/09 06:39:12 wiz Exp $

DISTNAME=	h2o-1.7.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=h2o/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/h2o/h2o
COMMENT=	Optimized HTTP server with support for HTTP/1.x and HTTP/2
LICENSE=	mit

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:run pkg-config
PKGCONFIG_OVERRIDE+=	libh2o-evloop.pc.in
PKGCONFIG_OVERRIDE+=	libh2o.pc.in

CMAKE_ARGS+=		-DWITH_BUNDLED_SSL=off
# TODO: make it an option
CMAKE_ARGS+=		-DWITH_MRUBY=off

SUBST_CLASSES+=		interp
SUBST_STAGE.interp=	post-extract
SUBST_MESSAGE.interp=	Fixing interpreter.
SUBST_FILES.interp=	share/h2o/*
SUBST_SED.interp=	-e 's,^\#\! /bin/sh,\#\!/bin/perl,'
SUBST_SED.interp+=	-e '/^exec perl/d'
SUBST_SED.interp+=	-e '/\#\! perl/d'

REPLACE_PERL=		share/h2o/*

.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../www/wslay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
