# $NetBSD: Makefile,v 1.10 2023/10/24 22:11:31 wiz Exp $

DISTNAME=	nostromo-2.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.nazgul.ch/dev/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ast@NetBSD.org
HOMEPAGE=	http://www.nazgul.ch/dev_nostromo.html
COMMENT=	Fast, secure HTTP/1.1 CGI/1.1 SSL IPv4/IPv6 webserver
LICENSE=	isc

USE_TOOLS+=	sed
MAKE_FILE=	GNUmakefile

RCD_SCRIPTS=	nostromo
EGDIR=		share/examples/nostromo

# Otherwise, libmy gets linked before it is generated
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	sbin share/examples/rc.d ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}/conf
INSTALLATION_DIRS+=	${EGDIR}/icons
INSTALLATION_DIRS+=	${EGDIR}/htdocs ${EGDIR}/htdocs/cgi-bin

SUBST_CLASSES+=		nostromo
SUBST_STAGE.nostromo=	post-extract
SUBST_FILES.nostromo=	GNUmakefile
SUBST_SED.nostromo+=	-e '/install -d -o root -g daemon -m 755/d'
SUBST_SED.nostromo+=	-e 's,cc ${CCFLAGS},${CC} ${CCFLAGS},g'
SUBST_SED.nostromo+=	-e 's,install -c -o root -g bin -m 555,${INSTALL},g'
SUBST_SED.nostromo+=	-e 's,install -c -o root -g bin -m 444,${INSTALL_MAN},g'
SUBST_SED.nostromo+=	-e 's,install -c -o root -g bin -m 644,${INSTALL_DATA},g'
SUBST_SED.nostromo+=	-e 's,/usr/local,${DESTDIR}${PREFIX},g'
SUBST_SED.nostromo+=	-e 's,/usr/share/man,${DESTDIR}${PREFIX}/${PKGMANDIR},g'
SUBST_SED.nostromo+=	-e 's,/var/nostromo,${DESTDIR}${PREFIX}/${EGDIR},g'

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
