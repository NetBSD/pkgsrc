# $NetBSD: Makefile,v 1.4 2001/05/14 14:12:31 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		gd
CATEGORIES+=		graphics
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for GD graphics library

DEPENDS+=		gd-*:../../graphics/gd

EVAL_PREFIX+=		GDDIR=gd
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${GDDIR}

USE_X11=		# defined

.include "../../mk/bsd.pkg.mk"
