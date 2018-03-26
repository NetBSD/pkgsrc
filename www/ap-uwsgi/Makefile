# $NetBSD: Makefile,v 1.3 2018/03/26 09:34:29 adam Exp $

.include  "../../www/py-uwsgi/Makefile.common"

LICENSE=	apache-2.0

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME}
COMMENT=	Apache proxy backend for the uWSGI protocol

CONFLICTS+=	apache24>=2.4.30

APACHE_MODULE=		YES
APACHE_MODULE_SRCDIR=	${WRKSRC}/apache2
APACHE_MODULE_SRC=	mod_proxy_uwsgi.c
APACHE_MODULE_NAME=	mod_proxy_uwsgi.la

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
