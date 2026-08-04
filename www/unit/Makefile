# $NetBSD: Makefile,v 1.29 2026/08/04 20:29:20 wiz Exp $

PKGREVISION= 1
.include "../../www/unit/version.mk"

DISTNAME=	unit-${UNIT_VERSION}

COMMENT=	Dynamic web application server

MAINTAINER=	pkgsrc-users@NetBSD.org

RCD_SCRIPTS=	unit

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
