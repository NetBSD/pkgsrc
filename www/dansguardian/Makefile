# $NetBSD: Makefile,v 1.28 2018/08/22 09:47:24 wiz Exp $

DISTNAME=	dansguardian-2.12.0.3
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dansguardian/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sborrill@NetBSD.org
#HOMEPAGE=	http://dansguardian.org/
COMMENT=	Fast, featureful web content filter for Squid proxy servers
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl pkg-config
RCD_SCRIPTS+=	dansguardian

# Fix bug in configure.ac: the paths are expanded too soon
SUBST_CLASSES+=		pathfix
SUBST_STAGE.pathfix=	pre-configure
SUBST_MESSAGE.pathfix=	Fixing premature variable expansion
SUBST_FILES.pathfix=	configs/Makefile.in
SUBST_FILES.pathfix+=	configs/*/Makefile.in
SUBST_FILES.pathfix+=	configs/*/*/Makefile.in
SUBST_SED.pathfix=	-e 's,@DGCONFDIR@,\$$(sysconfdir),'

DANSGUARDIAN_USER?=	dansgrdn
DANSGUARDIAN_GROUP?=	dansgrdn

PKG_USERS_VARS+=	DANSGUARDIAN_USER
PKG_GROUPS_VARS+=	DANSGUARDIAN_GROUP

PKG_GROUPS=		${DANSGUARDIAN_GROUP}
PKG_USERS=		${DANSGUARDIAN_USER}:${DANSGUARDIAN_GROUP}
PKG_GECOS.${DANSGUARDIAN_USER}=	Dansguardian webfilter pseudo-user

PKG_SYSCONFSUBDIR=	dansguardian
BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/log/dansguardian \
			${DANSGUARDIAN_USER} ${DANSGUARDIAN_GROUP} 0755

CONFIGURE_ARGS+=	--with-proxyuser=${DANSGUARDIAN_USER}
CONFIGURE_ARGS+=	--with-proxygroup=${DANSGUARDIAN_GROUP}
CONFIGURE_ARGS+=	--with-piddir=${VARBASE}/run
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/dansguardian
CONFIGURE_ARGS+=	CPPFLAGS=-DFD_SETSIZE=512

.include "options.mk"

CHECK_WRKREF_SKIP+=	sbin/dansguardian

REPLACE_PERL=		data/dansguardian.pl

EGDIR=			${PREFIX}/share/examples/dansguardian
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

EGDIRS!=		cat ${.CURDIR}/files/configdirs
.for d in ${EGDIRS}
OWN_DIRS+=		${PKG_SYSCONFDIR}/${d}
INSTALLATION_DIRS+=	${EGDIR}/${d}
.endfor

EGFILES!=		cat ${.CURDIR}/files/configfiles ${EGFILES_LIST}
.for f in ${EGFILES} ${EGFILES_EXTRA}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
