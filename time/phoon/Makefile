# $NetBSD: Makefile,v 1.14 2016/09/19 05:59:14 dholland Exp $
#

DISTNAME=	phoon_29jun2005
PKGNAME=	phoon-20050629
CATEGORIES=	time
MASTER_SITES=	http://www.acme.com/software/phoon/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/phoon/
COMMENT=	Show phase of the moon on ASCII terminal

WRKSRC=		${WRKDIR}/phoon

.include "../../mk/bsd.prefs.mk"

# doesn't have tm_gmtoff
.if ${OPSYS} == "Interix" || ${OPSYS} == "SunOS" || ${OPSYS} == "IRIX"
MAKE_FLAGS+=	DEFINES=-DOS_SYSV
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
