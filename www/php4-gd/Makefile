# $NetBSD: Makefile,v 1.3 2001/03/01 18:18:15 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		gd
CATEGORIES+=		graphics
PHP_PKG_VERS=		nb1

COMMENT=		PHP4 extension for GD graphics library

DEPENDS+=		gd-*:../../graphics/gd

EVAL_PREFIX+=		GDDIR=gd
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${GDDIR}

USE_X11=		# defined

.include "../../mk/bsd.pkg.mk"
