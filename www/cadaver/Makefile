# $NetBSD: Makefile,v 1.62 2023/11/08 13:21:16 wiz Exp $

DISTNAME=		cadaver-0.23.3
PKGREVISION=		15
CATEGORIES=		www
MASTER_SITES=		http://www.webdav.org/cadaver/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.webdav.org/cadaver/
COMMENT=		Command-line WebDAV client
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config

BUILD_TARGET=		cadaver
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--enable-netrc
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--with-ssl=gnutls
LIBS+=			${BUILDLINK_LDADD.termcap}

.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
