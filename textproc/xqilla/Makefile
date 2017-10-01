# $NetBSD: Makefile,v 1.3 2017/10/01 09:45:50 wiz Exp $

DISTNAME=	XQilla-2.3.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xqilla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xqilla.sourceforge.net/
COMMENT=	XQuery and XPath 2 processor
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
