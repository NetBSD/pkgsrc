# $NetBSD: Makefile,v 1.19 2014/11/24 05:23:17 mef Exp $
#

DISTNAME=	cgilib-0.7
CATEGORIES=	www
MASTER_SITES=	http://www.infodrom.org/projects/cgilib/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infodrom.org/projects/cgilib/
COMMENT=	Common gateway interface library
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man5
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec/cgi-bin
INSTALLATION_DIRS=	${PREFIX}/share/examples/cgilib

post-install:
	(cd ${WRKSRC}; \
	${INSTALL_DATA} jumpto.c cgitest.c ${DESTDIR}${PREFIX}/share/examples/cgilib)
.include "../../mk/bsd.pkg.mk"
