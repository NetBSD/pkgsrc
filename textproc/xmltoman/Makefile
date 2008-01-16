# $NetBSD: Makefile,v 1.1.1.1 2008/01/16 03:04:16 bjs Exp $
#

DISTNAME=	xmltoman_0.3.orig
PKGNAME=	${DISTNAME:S/_/-/:R}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xmltoman/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	# none
COMMENT=	XML to manual page converter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	perl:run
USE_LANGUAGES=	# none

#INSTALLATION_DIRS=	bin share/${PKGBASE} ${PKGMANDIR}/man1
AUTO_MKDIRS=		yes
MAKE_ENV+=		PKGBASE=${PKGBASE:Q}
REPLACE_PERL=		xmltoman xmlmantohtml
USE_BSD_MAKEFILE=	yes

post-extract:
	cp ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
