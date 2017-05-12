# $NetBSD: Makefile,v 1.5 2017/05/12 11:42:33 jperkin Exp $

DISTNAME=	e2guardian-3.5.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=e2guardian/}
GITHUB_PROJECT=	e2guardian
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.e2guardian.org/
COMMENT=	Web content filtering proxy
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
USE_TOOLS=	autoconf automake perl pkg-config
RCD_SCRIPTS+=	e2guardian

# Fix bug in configure.ac: the paths are expanded too soon
SUBST_CLASSES+=		pathfix
SUBST_STAGE.pathfix=	pre-configure
SUBST_MESSAGE.pathfix=	Fixing premature variable expansion
SUBST_FILES.pathfix=	configs/Makefile.am
SUBST_FILES.pathfix+=	configs/*/Makefile.am
SUBST_FILES.pathfix+=	configs/*/*/Makefile.am
SUBST_SED.pathfix=	-e 's,DGCONFDIR,sysconfdir,'

E2G_USER?=		e2grdn
E2G_GROUP?=		e2grdn
E2G_LOG?=		e2guardian

PKG_USERS_VARS+=	E2G_USER
PKG_GROUPS_VARS+=	E2G_GROUP

PKG_USERS=		${E2G_USER}:${E2G_GROUP}
PKG_GROUPS=		${E2G_GROUP}
PKG_GECOS.${E2G_USER}=	e2guardian webfilter pseudo-user

PKG_SYSCONFSUBDIR=	e2guardian
BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/log/e2guardian \
                        ${E2G_USER} ${E2G_GROUP} 0755

CONFIGURE_ARGS+=	--with-proxyuser=${E2G_USER}
CONFIGURE_ARGS+=	--with-proxygroup=${E2G_GROUP}
CONFIGURE_ARGS+=	--with-piddir=${VARBASE}/run
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/${E2G_LOG}
CONFIGURE_ARGS+=	--enable-ntlm

LIBS.SunOS+=		-liconv

.include "options.mk"

CHECK_WRKREF_SKIP= 	sbin/e2guardian

REPLACE_PERL+=		data/e2guardian.pl

EGDIR=			${PREFIX}/share/examples/e2guardian
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

EGDIRS!=		cat ${.CURDIR}/files/configdirs
.for d in ${EGDIRS}
OWN_DIRS+=		${PKG_SYSCONFDIR}/${d}
INSTALLATION_DIRS+=	${EGDIR}/${d}
.endfor

EGFILES!=		cat ${.CURDIR}/files/configfiles
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
