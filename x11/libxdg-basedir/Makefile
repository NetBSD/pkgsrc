# $NetBSD: Makefile,v 1.7 2022/07/25 11:12:30 wiz Exp $

DISTNAME=	libxdg-basedir-1.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=devnev/}
GITHUB_TAG=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/devnev/libxdg-basedir
COMMENT=	XDG Base Directory library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	pkgconfig/libxdg-basedir.pc.in

SUBST_CLASSES+=		pkglayout
SUBST_STAGE.pkglayout=	pre-configure
SUBST_FILES.pkglayout=	src/basedir.c
SUBST_SED.pkglayout=	-e 's|DIR_SEPARATOR_STR "etc"|"${PKG_SYSCONFDIR}"|g'
SUBST_SED.pkglayout+=	-e 's|DIR_SEPARATOR_STR "usr" DIR_SEPARATOR_STR "local"|"${PREFIX}"|g'
SUBST_SED.pkglayout+=	-e '/DefaultDataDirectories1\[\]/,/DefaultRelativeCacheHome\[\]/ s|/|" DIR_SEPARATOR_STR "|g'
SUBST_SED.pkglayout+=	-e '/DefaultDataDirectories1\[\]/,/DefaultRelativeCacheHome\[\]/ s|""||g'

SUBST_CLASSES+=		testsdir
SUBST_STAGE.testsdir=	post-build
SUBST_FILES.testsdir=	tests/*
SUBST_SED.testsdir=	-e 's|/etc/xdg|${PKG_SYSCONFDIR}/xdg|g'
SUBST_SED.testsdir+=	-e 's|/usr/local/share|${PREFIX}/share|g'

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
