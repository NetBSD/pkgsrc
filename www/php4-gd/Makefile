# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:32 wiz Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		gd
CATEGORIES+=		graphics

COMMENT=		PHP4 extension for GD graphics library

DEPENDS+=		gd-*:../../graphics/gd

EVAL_PREFIX+=		GDDIR=gd
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${GDDIR}

USE_X11=		# defined

.include "../../mk/bsd.pkg.mk"
