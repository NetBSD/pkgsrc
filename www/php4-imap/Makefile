# $NetBSD: Makefile,v 1.8 2001/04/30 03:31:26 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		imap
CATEGORIES+=		mail
PHP_PKG_VERS=		nb2

COMMENT=		PHP4 extension for IMAP (Internet Mailbox Access Protocol)

BUILD_DEPENDS+=		imap-uw>=2000.0.3nb1:../../mail/imap-uw

CCLIENT_PIC_LIB=	${LOCALBASE}/lib/libc-client_pic.a

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LOCALBASE}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=shared,${SSLBASE}

USE_SSL=		# defined

MAKE_ENV+=		LTLIBRARY_LDFLAGS="${LTLIBRARY_LDFLAGS}"

.if !defined(LTLIBRARY_LDFLAGS)
LTLIBRARY_LDFLAGS=	-Wl,--whole-archive -Wl,${CCLIENT_PIC_LIB}
LTLIBRARY_LDFLAGS+=	-Wl,-R${SSLBASE}/lib -L${SSLBASE}/lib -lcrypto -lssl
.endif

.include "../../mk/bsd.pkg.mk"
