# $NetBSD: Makefile,v 1.2 2017/09/06 09:03:06 wiz Exp $

DISTNAME=	xtrace_1.3.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.qa.debian.org/x/xtrace.html
COMMENT=	Trace communication between X11 client and server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

post-extract:
	${CP} ${FILESDIR}/tdestroy.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
