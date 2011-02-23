# $NetBSD: Makefile,v 1.1.1.1 2011/02/23 08:34:14 adam Exp $

DISTNAME=	XQilla-2.2.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xqilla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xqilla.sourceforge.net/
COMMENT=	XQuery and XPath 2 processor
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
