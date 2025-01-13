# $NetBSD: Makefile,v 1.3 2025/01/13 16:41:55 ktnb Exp $

DISTNAME=	xtrace_1.4.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrace/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.qa.debian.org/x/xtrace.html
COMMENT=	Trace communication between X11 client and server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

post-extract:
	${CP} ${FILESDIR}/tdestroy.c ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
