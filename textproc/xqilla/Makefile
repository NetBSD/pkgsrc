# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:18 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
