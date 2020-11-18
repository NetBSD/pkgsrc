# $NetBSD: Makefile,v 1.1 2020/11/18 14:01:05 nikita Exp $

DISTNAME=	hugo-0.78.2
PKGNAME=	go-${DISTNAME:S/hugo-/hugo-bin-/}
CATEGORIES=	www
GITHUB_PROJECT=	hugo
GITHUB_TYPE=	release
MASTER_SITES=	https://github.com/gohugoio/hugo/releases/download/v${PKGVERSION_NOREV}/
# \todo: I had to use this MSATER_SITES instead of the github type as it resulted in wrong URLs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gohugoio/hugo/
COMMENT=	Static Website Engine written in Go (binary builds)
LICENSE=	apache-2.0

CONFLICTS+=	hugo-[0-9]*
CONFLICTS+=	go-hugo-[0-9]*

# Prebuilt binaries provided by upstream
ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	NetBSD-*-aarch64
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-aarch64
ONLY_FOR_PLATFORM+=	OpenBSD-*-x86_64
ONLY_FOR_PLATFORM+=	OpenBSD-*-i386
ONLY_FOR_PLATFORM+=	OpenBSD-*-aarch64
#ONLY_FOR_PLATFORM+=	DragonFly-*-x86_64
#ONLY_FOR_PLATFORM+=	Darwin-*-x86_64

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_NetBSD-64bit.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_NetBSD-32bit.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_NetBSD-ARM.tar.gz
.endif

.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_FreeBSD-64bit.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-i386) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_FreeBSD-32bit.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-aarch64) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_FreeBSD-ARM.tar.gz
.endif

.if !empty(MACHINE_PLATFORM:MOpenBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_OpenBSD-64bit.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MOpenBSD-*-i386) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_OpenBSD-32bit.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MOpenBSD-*-aarch64) || make(distinfo) || make(makesum) || make(mdi)
DISTFILES:=	${DISTFILES} ${DISTNAME:S/-/_/}_OpenBSD-ARM.tar.gz
.endif

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${INSTALL} hugo ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
