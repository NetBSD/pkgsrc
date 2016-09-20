# $NetBSD: Makefile,v 1.5 2016/09/20 12:59:25 wiz Exp $

DISTNAME=	regxml-${SNAPSHOT_DATE}-${SNAPSHOT_HASH:C/(......).*/\1/}
PKGNAME=	regxml-0.0.${SNAPSHOT_DATE}
CATEGORIES=	textproc

# The master site does not have a stable distfile.
#
# You can download a distfile from
# <http://git.huoc.org/?p=regxml.git;a=snapshot;h=${SNAPSHOT_HASH};sf=tgz>
# but the timestamp in the gzip compression layer will be different
# almost every time, so it will fail the pkgsrc integrity tests.
# To deal with this, we keep a distfile in MASTER_SITE_LOCAL.
#
# To update to a newer snapshot:
#
# 1. Go to <http://git.huoc.org/?p=regxml.git;a=summary> and
#    choose an appropriate snapshot.  Make a note of the date
#    and the git hash.
# 2. Download the snapshot to your own computer.
# 3. Rename the downloaded snapshot to
#    regxml-${YYYYMMDD}-${FIRST_6_CHARS_OF_GIT_HASH}.tar.gz
# 4. Edit the SNAPSHOT_DATE and SNAPSHOT_HASH in thie Makefile.
# 5. Upload your copy of the snapshot to MASTER_SITE_LOCAL, which is
#    <http://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/>
# 6. Everything else you would normally do when updating to a new version
#    of a package.
#
SNAPSHOT_DATE=	20100901
SNAPSHOT_HASH=	d9f32668e0f75204abe7acfaf22981893520c7b6
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.huoc.org/?p=regxml.git;a=summary

COMMENT=	Command line utilities for XML stream manipulation
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake yacc
MAKE_FILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR} ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man3 ${PKGMANDIR}/man7

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlgrep/xmlgrep \
		${DESTDIR}${PREFIX}/bin/xmlgrep
	${INSTALL_PROGRAM} ${WRKSRC}/xmlsed/xmlsed \
		${DESTDIR}${PREFIX}/bin/xmlsed
	${INSTALL_MAN} ${WRKSRC}/doc/xmlgrep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/xmlsed.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/regxml.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/
	${INSTALL_MAN} ${WRKSRC}/doc/regxml_xml.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/
	${INSTALL_MAN} ${WRKSRC}/doc/xmltools.7 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
