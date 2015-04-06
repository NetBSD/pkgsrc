# $NetBSD: Makefile,v 1.30 2015/04/06 08:17:39 adam Exp $

DISTNAME=	mod_mono-2.10
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mod_mono/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mod_mono
COMMENT=	Apache module that provides ASP.NET support

APACHE_MODULE=		yes
PKG_APACHE_ACCEPTED=	apache22

CONF_FILES=		${PREFIX}/share/examples/httpd/mod_mono.conf\
			${PKG_SYSCONFDIR}/httpd/mod_mono.conf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no

.include "../../lang/mono2/buildlink3.mk"
.include "../../www/mono-xsp/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
