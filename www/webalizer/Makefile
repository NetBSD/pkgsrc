# $NetBSD: Makefile,v 1.74 2022/07/27 18:56:42 wiz Exp $

DISTNAME=	webalizer-2.23-08-src
PKGNAME=	webalizer-2.23.8
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.webalizer.org/
COMMENT=	Web server log file analysis program

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}
BDB_ACCEPTED=		db4 db5
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-dns

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/webalizer.conf.sample ${PKG_SYSCONFDIR}/webalizer.conf
DOC_SUBDIR=	share/doc/webalizer
DOCDIR=		${PREFIX}/${DOC_SUBDIR}
DOCFILES=	CHANGES Copyright DNS.README README README.FIRST

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples ${DOC_SUBDIR}

SUBST_CLASSES+=		webalizer
SUBST_STAGE.webalizer=	post-build
SUBST_FILES.webalizer=	sample.conf webalizer.1
SUBST_VARS.webalizer=	PKG_SYSCONFDIR

PKG_OPTIONS_VAR=	PKG_OPTIONS.webalizer
PKG_SUPPORTED_OPTIONS=	bzip2 geoip
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-bz2
.endif # option bzip2

.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip
CONFIGURE_ARGS+=	--with-geodb=${BUILDLINK_PREFIX.GeoIP}/share/GeoIP
.endif # option geoip

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}/${f}
.endfor

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
