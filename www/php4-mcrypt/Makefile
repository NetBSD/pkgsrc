# $NetBSD: Makefile,v 1.2 2001/05/14 14:12:32 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mcrypt
CATEGORIES+=		security
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

DEPENDS+=		libmcrypt>=2.2:../../security/libmcrypt

EVAL_PREFIX+=		MCRYPTDIR=libmcrypt
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MCRYPTDIR}

.include "../../mk/bsd.pkg.mk"
