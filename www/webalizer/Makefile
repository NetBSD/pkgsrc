# $NetBSD: Makefile,v 1.36 2005/12/05 23:55:23 rillig Exp $
#

DISTNAME=	webalizer-2.01-10-src
PKGNAME=	webalizer-2.1.10
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mrunix.net/webalizer/
COMMENT=	Web server log file analysis program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}
USE_PKGINSTALL=		YES
GNU_CONFIGURE=  	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-dns
CONFIGURE_ENV+=		ac_cv_GDLIB=${BUILDLINK_PREFIX.gd}/include

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/webalizer.conf.sample ${PKG_SYSCONFDIR}/webalizer.conf
_DOC_SUBDIR=	share/doc/webalizer
_DOCDIR=	${PREFIX}/${_DOC_SUBDIR}
_DOCFILES=	CHANGES Copyright DNS.README README README.FIRST

PLIST_ADD=	${WRKSRC}/.PLIST_ADD
PLIST_SRC=	${PKGDIR}/PLIST ${PLIST_ADD}

INSTALLATION_DIRS=	bin man/man1 share/examples ${_DOC_SUBDIR}

SUBST_CLASSES+=		webalizer
SUBST_STAGE.webalizer=	post-build
SUBST_FILES.webalizer=	sample.conf webalizer.1
SUBST_SED.webalizer=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

PKG_OPTIONS_VAR=	PKG_OPTIONS.webalizer
PKG_SUPPORTED_OPTIONS=  geoip
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
# we want the patch archive extracted...
_GEOPATCH=		geolizer_2.01-10-patch
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${_GEOPATCH}.20050520.tar.gz

# ... _and_ the patch applied automatically
PATCHFILES=		${_GEOPATCH}.20050520.tar.gz
PATCH_SITES=		http://sysd.org/proj/
PATCH_DIST_CAT=		${GZCAT} $$patchfile | ${TAR} -Oxf - "geolizer*/geolizer.patch"
PATCH_DIST_STRIP=	-p1
CONFIGURE_ARGS+=	--enable-geoip

_DOCFILES+=		GeoIP.README GeoIP.INSTALL

post-extract:
	cd ${WRKDIR}/${_GEOPATCH} &&			\
		${MV} INSTALL ${WRKSRC}/GeoIP.INSTALL &&\
		${MV} GeoIP.README ${WRKSRC}

.  include "../../net/GeoIP/buildlink3.mk"
.endif # option geoip

post-install:
	@${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
	@cd ${WRKSRC};						\
	for f in ${_DOCFILES}; do				\
		${INSTALL_DATA} $$f ${_DOCDIR}/$$f;		\
		${ECHO} "${_DOC_SUBDIR}/$$f" >> ${PLIST_ADD};	\
	done;
	@${ECHO} "@dirrm ${_DOC_SUBDIR}" >> ${PLIST_ADD};

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
