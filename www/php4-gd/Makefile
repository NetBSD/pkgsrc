# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:57 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		gd
CATEGORIES+=		graphics
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for GD graphics library

DEPENDS+=		gd-[0-9]*:../../graphics/gd

EVAL_PREFIX+=		GDDIR=gd
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${GDDIR}

USE_X11=		# defined

.include "../../mk/bsd.pkg.mk"
