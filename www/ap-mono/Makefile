# $NetBSD: Makefile,v 1.46 2020/11/05 09:09:18 ryoon Exp $

DISTNAME=	mod_mono-3.12
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=	13
CATEGORIES=	www
MASTER_SITES=	https://download.mono-project.com/sources/mod_mono/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/Mod_mono
COMMENT=	Apache module that provides ASP.NET support

APACHE_MODULE=		yes

CONF_FILES=		${PREFIX}/share/examples/httpd/mod_mono.conf\
			${PKG_SYSCONFDIR}/httpd/mod_mono.conf

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no

.include "../../lang/mono/buildlink3.mk"
.include "../../www/mono-xsp/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
