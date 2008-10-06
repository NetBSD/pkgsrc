# $NetBSD: Makefile,v 1.1.1.1 2008/10/06 10:52:29 kefren Exp $

DISTNAME=	mod_mono-${MOD_MONO_VER}
PKGNAME=	ap-mono-${MOD_MONO_VER}
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mod_mono/
EXTRACT_SUFX=	.tar.bz2
MOD_MONO_VER=	1.9

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mod_mono
COMMENT=	Apache module that provides ASP.NET support

APACHE_MODULE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES=		${PREFIX}/share/examples/httpd/mod_mono.conf\
			${PKG_SYSCONFDIR}/httpd/mod_mono.conf

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

.include "../../lang/mono/buildlink3.mk"
.include "../../www/mono-xsp/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
