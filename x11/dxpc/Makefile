# $NetBSD: Makefile,v 1.16 2003/06/02 01:15:46 jschauma Exp $
#

DISTNAME=		dxpc-3.8.1
CATEGORIES=		x11
MASTER_SITES=		http://www.vigor.nu/dxpc/3.8.1/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.vigor.nu/dxpc/
COMMENT=		Differential X Protocol Compressor

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
CONFIGURE_ENV+=	CXX=${LOCALBASE}/egcs/bin/g++
.endif

post-install:
	@strip ${PREFIX}/bin/dxpc

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
