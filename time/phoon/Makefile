# $NetBSD: Makefile,v 1.9 2006/09/23 22:12:15 schwarz Exp $
#

DISTNAME=	phoon_01apr1995
PKGNAME=        phoon-19950401
CATEGORIES=	time
MASTER_SITES=	http://www.acme.com/software/phoon/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/phoon/
COMMENT=	Show phase of the moon on ASCII terminal

WRKSRC=		${WRKDIR}/phoon

.include "../../mk/bsd.prefs.mk"

# doesn't have tm_gmtoff
.if ${OPSYS} == "Interix" || ${OPSYS} == "SunOS" || ${OPSYS} == "IRIX"
MAKE_FLAGS+=	DEFINES=-DSYSV
.endif

.include "../../mk/bsd.pkg.mk"
