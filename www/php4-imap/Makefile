# $NetBSD: Makefile,v 1.2 2001/02/01 22:20:23 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		imap
CATEGORIES+=		mail

DEPENDS+=		imap-uw-2000*:../../mail/imap-uw

EVAL_PREFIX+=		IMAPDIR=imap-uw
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${IMAPDIR}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=shared,${SSLBASE}

USE_SSL=		# defined

.include "../../mk/bsd.pkg.mk"
