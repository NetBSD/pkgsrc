# $NetBSD: Makefile,v 1.7 2009/07/06 22:22:40 joerg Exp $

DISTNAME=	mod_mono-2.4
PKGNAME=	${APACHE_PKG_PREFIX}-mono-2.4
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mod_mono/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mod_mono
COMMENT=	Apache module that provides ASP.NET support

APACHE_MODULE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES=		${PREFIX}/share/examples/httpd/mod_mono.conf\
			${PKG_SYSCONFDIR}/httpd/mod_mono.conf

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no

.include "../../lang/mono/buildlink3.mk"
.include "../../www/mono-xsp/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
