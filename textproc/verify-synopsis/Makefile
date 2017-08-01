# $NetBSD: Makefile,v 1.2 2017/08/01 15:09:52 wiz Exp $

DISTNAME=	verify-synopsis-1.0
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

OWNER=		wiz@NetBSD.org
#HOMEPAGE=	#
COMMENT=	Tool for verifying man pages' SYNOPSIS
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 libexec

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
DEPENDS+=	mandoc-[0-9]*:../../textproc/mandoc
.endif

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-extract
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	verify-synopsis
SUBST_MESSAGE.prefix=	Fixing prefix.

do-extract:
	cd ${FILESDIR} && cp d* v* ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/verify-synopsis ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dmpsynopsis.awk ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${FILESDIR}/verify-synopsis.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
