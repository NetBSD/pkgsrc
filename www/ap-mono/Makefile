# $NetBSD: Makefile,v 1.63 2026/11/25 17:16:33 wiz Exp $

DISTNAME=	mod_mono-3.13
PKGNAME=	ap24-${DISTNAME:S/mod_//}
PKGREVISION=	13
CATEGORIES=	www
MASTER_SITES=	https://download.mono-project.com/sources/mod_mono/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/Mod_mono
COMMENT=	Apache module that provides ASP.NET support
LICENSE=	apache-2.0

APACHE_MODULE=		yes

CONF_FILES=		${PREFIX}/share/examples/httpd/mod_mono.conf\
			${PKG_SYSCONFDIR}/httpd/mod_mono.conf

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no

.include "../../lang/mono/buildlink3.mk"
.include "../../www/apache24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
