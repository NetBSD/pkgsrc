# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:36 rillig Exp $

DISTNAME=	XQilla-2.3.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xqilla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xqilla.sourceforge.net/
COMMENT=	XQuery and XPath 2 processor
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
