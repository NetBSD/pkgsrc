# $NetBSD: Makefile,v 1.14 2001/10/22 01:05:40 mjl Exp $
#

DISTNAME=		dxpc-3.8.1
CATEGORIES=		x11
MASTER_SITES=		http://www.vigor.nu/dxpc/3.8.1/ \
			${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.vigor.nu/dxpc/
COMMENT=		Differential X Protocol Compressor

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
.endif

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
